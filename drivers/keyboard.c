#include <drivers/keyboard.h>
#include <drivers/ports.h>
#include <drivers/screen.h>

#include <cpu/isr.h>

#define BACKSPACE 0x0E
#define ENTER 0x1C

static char key_buffer[256];

#define SC_MAX 57
const char *sc_name[] = { "ERROR", "Esc", "1", "2", "3", "4", "5", "6", 
    "7", "8", "9", "0", "°", "+", "Backspace", "Tab", "A", "Z", "E", 
    "R", "T", "Y", "U", "I", "O", "P", "^", "$", "Enter", "Lctrl", 
    "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "ù", "²", 
    "LShift", "<", "W", "X", "C", "V", "B", "N", ",", ";", ":", 
    "!", "RShift", "Keypad *", "LAlt", "Spacebar"};

const char sc_ascii[] = { '?', '?', '&', 'é', '"', '\'', '(', '-',     
    'è', '_', 'ç', 'à', ')', '=', '?', '?', 'a', 'z', 'e', 'r', 't', 'y', 
    'u', 'i', 'o', 'p', '^', '$', '?', '?', 'q', 's', 'd', 'f', 'g', 
    'h', 'j', 'k', 'l', 'm', 'ù', '²', '?', '<', 'w', 'x', 'c', 'v', 
    'b', 'n', ',', ';', ':', '!', '?', '?', '?', ' '};

static void keyboard_callback(registers_t regs) {
    /* The PIC leaves us the scancode in port 0x60 */
    u8 scancode = readByteFromPort(0x60);
    
    if (scancode > SC_MAX) return;
    if (scancode == BACKSPACE) {
        backspace(key_buffer);
        printBackspace();
    } else if (scancode == ENTER) {
        print("\n");
        userInput(key_buffer); /* kernel-controlled function */
        key_buffer[0] = '\0';
    } else {
        char letter = sc_ascii[(int)scancode];
        /* Remember that print only accepts char[] */
        char str[2] = {letter, '\0'};
        append(key_buffer, letter);
        print(str);
    }
}

void initKeyboard() {
   register_interrupt_handler(IRQ1, keyboard_callback); 
}
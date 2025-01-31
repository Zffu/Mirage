#include "../drivers/screen.h"
#include "../drivers/keyboard.h"

#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"

#include "../lib/str.h"

void main() {
    clearScreen();

    print("[INFO] Loading Mirage v1.0.0\n\n");

    isr_install();
    
    print("[");
    printWithColor("OK", GREEN_ON_BLACK);
    print("] Loaded ISR & IDT\n");

    asm volatile("sti");
    initCPUTimer(50);

    initKeyboard();

    print("[");
    printWithColor("OK", GREEN_ON_BLACK);
    print("] Loaded Keyboard Interuption handler");
}

void userInput(char* input) {
    if(strcmp(input, "exit") == 0) {
        print("Bye bye!");
        asm volatile("hlt");
    }

    print("Input:");
    print(input);
    print("\n> "); 
}
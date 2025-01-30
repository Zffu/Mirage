#include "../drivers/screen.h"
#include "../drivers/keyboard.h"

#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"

#include "../lib/str.h"

void main() {
    clearScreen();

    print("Loading Mirage v1.0.0");

    isr_install();
    
    asm volatile("sti");
    initCPUTimer(50);

    clearScreen();
    print("Mirage v1.0.0 by Zffu\n>  ");

    initKeyboard();
}

void userInput(char* input) {
    if(strcmp(input, "EXIT") == 0) {
        print("Bye bye!");
        asm volatile("hlt");
    }

    print("Input:");
    print(input);
    print("\n> "); 
}
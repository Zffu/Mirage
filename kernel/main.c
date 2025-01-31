#include "../drivers/screen.h"
#include "../drivers/keyboard.h"

#include "./delegations/delegations.h"

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
    print("] Loaded Keyboard Interuption handler\n");

    print("[INFO] Granting intial delegation powers\n");
    
    DELEGATE* delegate = createDelegate("delegation", 0x00);

    DELEGATE* d = createDelegate("walter", 0x00);

    print("[");
    printWithColor("OK", GREEN_ON_BLACK);
    print("] Delegated the following context:");
}

void userInput(char* input) {
    if(strcmp(input, "exit") == 0) {
        print("[");
        printWithColor("WARN", YELLOW_ON_BLACK);
        print("] Instant CPU Termination Requested!");
        asm volatile("hlt");
    }

    print("Input:");
    print(input);
    print("\n> "); 
}
#include "../drivers/screen.h"
#include "../drivers/keyboard.h"

#include "./delegations/delegations.h"

#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/timer.h"

#include "../lib/str.h"
#include "./utils/str.h"

DELEGATE* currentDelegate;

void showInputReady() {
    print("\n");
    printWithColor("@", LIGHT_MAGENTA_ON_BLACK);
    printWithColor(currentDelegate->name, LIGHT_MAGENTA_ON_BLACK);

    print("  > ");
}

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
    
    currentDelegate = createDelegate("delegation", 0x00);

    print("[");
    printWithColor("OK", GREEN_ON_BLACK);
    print("] Switched state to the following delegation: ");

    printWithColor("@", LIGHT_MAGENTA_ON_BLACK);
    printWithColor(currentDelegate->name, MAGENTA_ON_BLACK);

    print("\n");

    showInputReady();
}

void userInput(char* input) {
    if(strcmp(input, "exit") == 0) {
        print("[");
        printWithColor("WARN", YELLOW_ON_BLACK);
        print("] Instant CPU Termination Requested!");
        asm volatile("hlt");
        return;
    }

    strsplit(input, ' ');

    if(strcmp(input, "delegations") == 0) {        
        print("Permitted Delegations: (");
        
        char w[3];
        int_to_ascii(getDelegateCount(), w);
        
        print(w);
        print(")\n");

        DELEGATION_ENTRY* delegate = getMainDelegate();

        unsigned char flag = 0x01;

        while(delegate != 0 || flag == 0x01) {
            flag = 0x00;

            print("   -  ");
            print("Delegate ID: ");
            print(delegate->name);
            print(", Level: ");

            int_to_ascii(delegate->level, w);
            print(w);
            print("\n");

            delegate = delegate->next;
        }
    }

    showInputReady();
}
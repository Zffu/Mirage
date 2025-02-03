#include <kernel/delegations/delegations.h>
#include <kernel/loader/logger.h>
#include <kernel/fs.h>

#include <drivers/screen.h>
#include <drivers/keyboard.h>

#include <cpu/isr.h>
#include <cpu/idt.h>
#include <cpu/timer.h>

#include <libc/str.h>

DELEGATE* currentDelegate;

void showInputReady() {
    print("\n");
    printWithColor("@", LIGHT_MAGENTA_ON_BLACK);
    printWithColor(currentDelegate->name, LIGHT_MAGENTA_ON_BLACK);

    print("  > ");
}

void main() {
    clearScreen();

    l_loginfo("Starting Kernel startup sequence");

    isr_install();
    l_logok("Loaded & Installed CPU ISR");

    asm volatile("sti");
    initCPUTimer(50);

    initKeyboard();
    l_logok("Loaded Keyboard Interruption handler");

    currentDelegate = createDelegate("delegation", 0x00);

    l_logok("Granted original delegation");

    initFS();

    print("\n");
    showInputReady();
}

void userInput(char* input) {
    if(strcmp(input, "exit") == 0) {
        l_logwarn("Instant CPU Termination requested!");
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
    else if(strcmp(input, "fsl") == 0) {
        listFiles();
    }
    else if (strcmp(input, "write") == 0) {
        char* filename = strnextsegment(input);
        char* data = strnextsegment(filename);
        writeFile(filename, data, strlen(data));
        print("File written successfully\n");
    }

    showInputReady();
}
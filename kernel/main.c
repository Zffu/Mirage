#include "../drivers/screen.h"

void main() {
    clearScreen();

    /* Fill up the screen */
    int i = 0;
    for (i = 0; i < 24; i++) {
        printAt("Loading WalterOS...",0,i);
    }

    printAt("This text forces the kernel to scroll. Row 0 will disappear. ", 60, 24);
    print("And with this text, the kernel will scroll again, and row 1 will disappear too!");
}
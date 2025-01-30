#include "../drivers/screen.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"

void main() {
    clearScreen();

    print("Loading Mirage v1.0.0");

    isr_install();
    /* Test the interrupts */
    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");

}
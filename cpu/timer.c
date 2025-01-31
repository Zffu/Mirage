#include <cpu/timer.h>
#include <cpu/isr.h>

#include <drivers/screen.h>
#include <drivers/ports.h>

#include "../kernel/utils/str.h"

u32 tick = 0;

static void timer_callback(registers_t regs) {
    tick++;
}

void initCPUTimer(u32 freq) {
    /* Install the function we just wrote */
    register_interrupt_handler(IRQ0, timer_callback);

    /* Get the PIT value: hardware clock at 1193180 Hz */
    u32 divisor = 1193180 / freq;
    u8 low  = (u8)(divisor & 0xFF);
    u8 high = (u8)( (divisor >> 8) & 0xFF);
    /* Send the command */
    writeByteInPort(0x43, 0x36); /* Command port */
    writeByteInPort(0x40, low);
    writeByteInPort(0x40, high);
}
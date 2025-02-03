
#include <drivers/ports.h>

void swapToGraphicsMode() {
    writeByteInPort(0x3C0, 0x10); // Set graphics mode
    writeByteInPort(0x3C0, 0x13);
    writeByteInPort(0x3C0, 0x20); // Enable display
}

void swapToTextMode() {
    writeByteInPort(0x3C0, 0x10); // Set text mode
    writeByteInPort(0x3C0, 0x03);
    writeByteInPort(0x3C0, 0x20); // Enable display
}

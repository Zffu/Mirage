#ifndef DRIVER_VGA_H
#define DRIVER_VGA_H

#define VGA_WIDTH 320
#define VGA_HEIGHT 200
#define VGA_GRAPHICS_MODE 0x13
#define VGA_TEXT_MODE 0x03

void swapToGraphicsMode();
void swapToTextMode();

#endif
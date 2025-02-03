#ifndef VGA_GRAPHICS_DRIVER_H
#define VGA_GRAPHICS_DRIVER_H

typedef unsigned char col;

void setPixel(int x, int y, col color);
void drawRect(int x, int y, int width, int height, col color);
void drawLine(int x1, int y1, int x2, int y2, col color);


#endif
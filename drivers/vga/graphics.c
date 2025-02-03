#include <drivers/vga/graphics.h>
#include <drivers/vga/vga.h>

unsigned char* VGA_GRAPHICS_MEMORY = (unsigned char*) 0xA0000;

void setPixel(int x, int y, col color) {
        if (x >= 0 && x < VGA_WIDTH && y >= 0 && y < VGA_HEIGHT) {
        unsigned int offset = y * VGA_WIDTH + x;
        VGA_GRAPHICS_MEMORY[offset] = color;
    }
}

void drawRect(int x, int y, int width, int height, col color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            setPixel(x + j, y + i, color);
        }
    }
}

void drawLine(int x1, int y1, int x2, int y2, col color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    
    float x = x1;
    float y = y1;
    
    for (int i = 0; i <= steps; i++) {
        setPixel((int)x, (int)y, color);
        x += xInc;
        y += yInc;
    }
}

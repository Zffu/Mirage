/**
 * The screen driver.
 */

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define BLACK_ON_BLACK 0x00
#define BLUE_ON_BLACK 0x01
#define GREEN_ON_BLACK 0x02
#define CYAN_ON_BLACK 0x03
#define RED_ON_BLACK 0x04
#define MAGENTA_ON_BLACK 0x05
#define BROWN_ON_BLACK 0x06
#define LIGHT_GRAY_ON_BLACK 0x07
#define DARK_GRAY_ON_BLACK 0x08
#define LIGHT_BLUE_ON_BLACK 0x09
#define LIGHT_GREEN_ON_BLACK 0x0A
#define LIGHT_CYAN_ON_BLACK 0x0B
#define LIGHT_RED_ON_BLACK 0x0C
#define LIGHT_MAGENTA_ON_BLACK 0x0D
#define YELLOW_ON_BLACK 0x0E
#define WHITE_ON_BLACK 0x0f




#define RED_ON_WHITE 0xf4

// Screen IO Ports
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5


#ifndef SCREEN_DRIVER_H
#define SCREEN_DRIVER_H

/**
 * Clears the screen.
 */
void clearScreen();

/**
 * Prints a string at the specified location
 */
void printAt(char* str, int col, int row);


/**
 * Prints a string.
 */
void print(char* str);

void printAtWithColor(char* str, int col, int row, int color);
void printWithColor(char* str, int color);

void printBackspace();

#endif
/**
 * The screen driver.
 */

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f
#define GREEN_ON_BLACK 0x02
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
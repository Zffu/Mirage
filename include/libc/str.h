#ifndef LIB_STRING
#define LIB_STRING

/**
 * Compares the two strings and returns the delta value.
 * If ret == 0, the strings are equal.
 */
int strcmp(char* s1, char* s2);

/**
 * Gives the length of the string until the first \0 is met.
 */
int strlen(char* s);

/**
 * Appends a char at the end of the string buffer. (When \0 is met)
 */
void append(char* s, char n);

/**
 * Backspaces into the string.
 */
void backspace(char* s);

/**
 * Splits the strings into segments (Delimited by \0).
 */
void strsplit(char* s, char sep);

/**
 * Gets the next string segment
 */
char* strnextsegment(char* s);

/**
 * Converts an integer to ascii.
 */
void int_to_ascii(int n, char str[]);

#endif
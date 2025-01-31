#include <cpu/types.h>

#ifndef LIB_MEM
#define LIB_MEM

/**
 * Allocates a specific amount of bytes and returns the address.
 */
u32 malloc(u32 size);

/**
 * Copies the bytes.
 */
void memcpy(char* source, char* target, int size);

#endif
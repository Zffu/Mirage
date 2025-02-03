#include <cpu/types.h>
#include <kernel/internal/mem.h>

/**
 * Allocates a specific amount of bytes and returns the address.
 */
u32 malloc(u32 size) {
    if(size < 1) return -1;

    u32 paddr;
    return k_malloc(size, 1, paddr);
}

/**
 * Copies the bytes
 */
void memcpy(char* source, char* target, int size) {
    for(int i = 0; i < size; ++i) {
        *(target + i) = *(source + i);
    }
}
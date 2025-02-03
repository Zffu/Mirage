/**
 * Internal functions for memory allocation.
 */

#include <cpu/types.h>

#ifndef KERNEL_INTERNAL_MEM
#define KERNEL_INTERNAL_MEM

/**
 * Internally allocates a set amount of bytes and returns the address.
 * This function is seperated from malloc to provide a direct allocation access to the kernel.
 */
u32 k_malloc(u32 size, int align, u32* physicalAddr);

#endif
/**
 * Internal functions for memory allocation.
 */

#include <cpu/types.h>

#ifndef KERNEL_INTERNAL_MEM
#define KERNEL_INTERNAL_MEM

#define KERNEL_MEMORY_SPACE_START 0x10000
#define KERNEL_MEMORY_SPACE_END 0x100000

/**
 * Internally allocates a set amount of bytes and returns the address.
 * This function is seperated from malloc to provide a direct allocation access to the kernel.
 */
u32 k_malloc(u32 size, int align, u32* physicalAddr, unsigned char ring);

int isKernelAllocatedMemory(u32 addr);

#endif
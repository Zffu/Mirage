/**
 * Internal functions for memory allocation.
 */

#include <cpu/types.h>

/**
 * This value should be computed at link time but hardcoded is fine for now
 * 
 * The kernel starts at 0x1000 
 */
u32 free_mem_addr = 0x10000;

/**
 * Internally allocates a set amount of bytes and returns the address.
 * This function is seperated from malloc to provide a direct allocation access to the kernel.
 */
u32 k_malloc(u32 size, int align, u32* physicalAddr) {
    /* Pages are aligned to 4K, or 0x1000 */
    if (align == 1 && (free_mem_addr & 0xFFFFF000)) {
        free_mem_addr &= 0xFFFFF000;
        free_mem_addr += 0x1000;
    }
    /* Save also the physical address */
    if (physicalAddr) *physicalAddr = free_mem_addr;

    u32 ret = free_mem_addr;
    free_mem_addr += size; /* Remember to increment the pointer */
    return ret;
}
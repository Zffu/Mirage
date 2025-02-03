/**
 * Internal functions for memory allocation.
 */

#include <kernel/internal/mem.h>
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
u32 k_malloc(u32 size, int align, u32* physicalAddr, unsigned char ring) {
    // Check if allocation is in kernel space
    if ((free_mem_addr < KERNEL_MEMORY_SPACE_START || 
        (free_mem_addr + size) > KERNEL_MEMORY_SPACE_END) && ring != 0x00) {
        return 0; // Invalid allocation
    }

    if (align) {
        free_mem_addr &= 0xFFFFF000;
        free_mem_addr += 0x1000;
    }

    if (physicalAddr) *physicalAddr = free_mem_addr;

    u32 ret = free_mem_addr;
    free_mem_addr += size;
    
    // Mark memory as kernel-only by setting supervisor bit
    u32* page_entry = (u32*)ret;
    *page_entry |= 0x00000002; // Set supervisor bit
    
    return ret;
}

int isKernelAllocatedMemory(u32 addr) {
    return (addr >= KERNEL_MEMORY_SPACE_START && addr < KERNEL_MEMORY_SPACE_END);
}
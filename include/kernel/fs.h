#include <cpu/types.h>

#ifndef KERNEL_FS
#define KERNEL_FS

#define KERNEL_FS_START_SECTOR 2048
#define KERNEL_FS_MAX_FILES 64

typedef struct KERNEL_FS_ENTRY {

    unsigned char type;
    char* name;
    u32 size;
    u32 start_sector;
    u32 num_sector;

} KERNEL_FS_ENTRY;

/**
 * Intializes the File system.
 */
void initFS();
u8 writeFile(char* name, u8* data, u32 size);

void listFiles();


#endif
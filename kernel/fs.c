#include <drivers/ata.h>

#include <kernel/fs.h>
#include <kernel/internal/mem.h>
#include <kernel/loader/logger.h>

#include <libc/mem.h>

KERNEL_FS_ENTRY* kernelFileTable;
u32 kernelNumFiles = 0;


/**
 * Intializes the File system.
 */
void initFS() {
    ata_init();
    
    l_logok("Loaded ATA driver");

    kernelFileTable = k_malloc(sizeof(KERNEL_FS_ENTRY) * KERNEL_FS_MAX_FILES, 1, 0);

    u8 buff[512];
    ata_read_sector(KERNEL_FS_START_SECTOR, buff);
    memcpy(buff, (char*)kernelFileTable, sizeof(kernelFileTable));

    l_logok("Retrieved file table!");
    kernelNumFiles = *((u32*)(buff + sizeof(kernelFileTable)));
}

u8 writeFile(char* name, u8* data, u32 size) {
    if (kernelNumFiles >= KERNEL_FS_MAX_FILES) return 0;
    
    // Find free sectors for file data
    u32 sectors_needed = (size + 511) / 512;
    u32 start_sector = KERNEL_FS_START_SECTOR + 1;
    
    // Create file entry
    KERNEL_FS_ENTRY* entry = &kernelFileTable[kernelNumFiles++];
    entry->type = 0x00; // File
    memcpy(name, entry->name, strlen(name) + 1);
    entry->size = size;
    entry->start_sector = start_sector;
    entry->num_sector = sectors_needed;
    
    // Write file data
    for (u32 i = 0; i < sectors_needed; i++) {
        ata_write_sector(start_sector + i, data + (i * 512));
    }
    
    // Update file table on disk
    ata_write_sector(KERNEL_FS_START_SECTOR, (u8*)kernelFileTable);
    return 1;
}

void listFiles() {
    for(u32 i = 0; i < kernelNumFiles; i++) {
        KERNEL_FS_ENTRY* entry = &kernelFileTable[i];
        if(entry->type != 0x02) { // Deleted
            // Print file info
            print(entry->name);
            print("  Size: ");
            char size_str[16];
            int_to_ascii(entry->size, size_str);
            print(size_str);
            print(" bytes\n");
        }
    }
    
    if(kernelNumFiles == 0) {
        print("No files found.\n");
    }
}
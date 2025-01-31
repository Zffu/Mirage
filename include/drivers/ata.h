#include <cpu/types.h>

#ifndef DRIVER_ATA_H
#define DRIVER_ATA_H

#define ATA_PRIMARY_IO 0x1F0
#define ATA_PRIMARY_DCR_AS 0x3F6


void ata_init();
u8 ata_read_sector(u32 lba, u8* buff);
u8 ata_write_sector(u32 lba, u8* buff);

#endif
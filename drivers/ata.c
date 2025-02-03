#include <drivers/ports.h>
#include <drivers/ata.h>
#include <drivers/screen.h>

#include <cpu/types.h>

#include <libc/str.h>

void ata_init() {
    writeByteInPort(ATA_PRIMARY_IO + 6, 0xA0);
    writeByteInPort(ATA_PRIMARY_DCR_AS, 0x02);
}

u8 ata_read_sector(u32 lba, u8* buff) {
    // Wait if busy
    while(readByteFromPort(ATA_PRIMARY_IO + 7) & 0x80);

    print("Beyond busy\n");

    // Set up parameters
    writeByteInPort(ATA_PRIMARY_IO + 6, 0xE0 | ((lba >> 24) & 0x0F));
    writeByteInPort(ATA_PRIMARY_IO + 1, 0x00);
    writeByteInPort(ATA_PRIMARY_IO + 2, 0x01);
    writeByteInPort(ATA_PRIMARY_IO + 3, (u8)lba);
    writeByteInPort(ATA_PRIMARY_IO + 4, (u8)(lba >> 8));
    writeByteInPort(ATA_PRIMARY_IO + 5, (u8)(lba >> 16));
    writeByteInPort(ATA_PRIMARY_IO + 7, 0x20); // Read command

    // Wait if busy
    while(readByteFromPort(ATA_PRIMARY_IO + 7) & 0x80);

    print("Beyond second busy\n");

    // Read sector data
    for(int i = 0; i < 256; i++) {
        u16 data = readWordFromPort(ATA_PRIMARY_IO);
        *((u16*)buff + i) = data;
        print("Beyond loop setor ");
        
        char v[5];
        int_to_ascii(i, v);
        print(v);
        print("\n");
        
    }

    print("Beyond read\n");

    return 1;
}

u8 ata_write_sector(u32 lba, u8* buff) {
    while(readByteFromPort(ATA_PRIMARY_IO + 7) & 0x80); // Wait if busy

    writeByteInPort(ATA_PRIMARY_IO + 6, 0xE0 | ((lba >> 24) & 0x0F));
    writeByteInPort(ATA_PRIMARY_IO + 1, 0x00);
    writeByteInPort(ATA_PRIMARY_IO + 2, 0x01);
    writeByteInPort(ATA_PRIMARY_IO + 3, (u8)lba);
    writeByteInPort(ATA_PRIMARY_IO + 4, (u8)(lba >> 8));
    writeByteInPort(ATA_PRIMARY_IO + 5, (u8)(lba >> 16));
    writeByteInPort(ATA_PRIMARY_IO + 7, 0x30); // Write command

    // Wait if busy
    while(readByteFromPort(ATA_PRIMARY_IO + 7) & 0x80);

    // Write sector data
    for(int i = 0; i < 256; i++) {
        writeWordInPort(ATA_PRIMARY_IO, *((u16*)buff + i));
    }

    return 1;
}
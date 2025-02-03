void init_pic() {
    // ICW1: start initialization sequence
    writeByteInPort(0x20, 0x11);
    writeByteInPort(0xA0, 0x11);
    
    // ICW2: vector offset
    writeByteInPort(0x21, 0x20);
    writeByteInPort(0xA1, 0x28);
    
    // ICW3: cascading
    writeByteInPort(0x21, 0x04);
    writeByteInPort(0xA1, 0x02);
    
    // ICW4: environment info
    writeByteInPort(0x21, 0x01);
    writeByteInPort(0xA1, 0x01);
    
    // Clear masks
    writeByteInPort(0x21, 0x00);
    writeByteInPort(0xA1, 0x00);
}
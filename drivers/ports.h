#ifndef DRIVER_PORTS_H
#define DRIVER_PORTS_H

unsigned char readByteFromPort(unsigned short port);
void writeByteInPort(unsigned short port, unsigned char data);

unsigned short readWordFromPort(unsigned short port);
void writeWordInPort(unsigned short port, unsigned short data);

#endif
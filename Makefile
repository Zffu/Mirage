C_SOURCES = $(wildcard kernel/*.c kernel/**/*.c drivers/*.c cpu/*.c libc/*.c)
HEADERS = $(wildcard include/*.h include/*/*.h)

# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o}

# -g: Use debugging symbols in gcc
CFLAGS = -g -Iinclude

all: os-image.bin
image: os-image.bin

kernel: kernel.bin
bootloader: boot/sector.bin

# First rule is run by default
os-image.bin: boot/sector.bin kernel.bin
	copy /b boot\sector.bin + kernel.bin os-image.bin


# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
kernel.bin: boot/kernel_entry.o ${OBJ}
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

# Used for debugging purposes
kernel.elf: boot/kernel_entry.o ${OBJ}
	i686-elf-ld -o $@ -Ttext 0x1000 $^ 

run: os-image.bin
	qemu-system-i386 -fda os-image.bin

# Open the connection to qemu and load our kernel-object file with symbols
debug: os-image.bin kernel.elf
	qemu-system-i386 -s -fda os-image.bin &
	gdb -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	i686-elf-gcc ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	del /Q /F *.bin *.dis *.o os-image.bin *.elf
	del /Q /F kernel\*.o boot\*.bin drivers\*.o boot\*.o cpu\*.o lib\*.o 
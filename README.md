# Mirage
Mirage is an operating system. I was really bored

## Building

You will need [elf tools](https://github.com/lordmilko/i686-elf-tools/releases)

You can build the Mirage kernel & Image by doing:
```
make all # Builds all of the Operating System
make kernel # Builds the Kernel
make image # Builds an image oft the operating system
make bootloader # Builds the bootloader
```

## Running

You can run the Operating system using Qemu by doing:
```
make run
```

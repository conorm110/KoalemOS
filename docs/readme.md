# KoalemOS
KoalemOS is a 32 bit operating system build on a custom  kernel for educational purposes. While the end goal is to be able to use KoalemOS as a daily OS, it is not meant to be run like that.


# Installation
## Requirements
**OS**: Linux OR WSL in Win11 (Debian)
**Virtualization**: QEMU
**Compiler**: GCC
**Assembler**: NASM
**Other**: Python
## Setup
In WSL (Debian):
```bash
sudo apt update
sudo apt upgrade
sudo apt install qemu
sudo apt install qemu-system-i386
sudo apt install nasm
git clone https://github.com/conorm110/KoalemOS
```
## Build
Build and run:
```bash
cd KoalemOS/osbuild
make
```
Cleanup:
```bash
cd KoalemOS
python3 clean.py
cd osbuild
make clean
```

## Run

Running KoalemOS is simply:
```bash
make run
```
However, in the makefile you may want to edit the qemu command to change the size, number, and mode of the disks.

# Kernel 
The kernel is a pretty standard microkernel. It has access to all the drivers, file system, and libraries and directly shares them with the operating system. It is written for i386 processors in legacy boot.
## Drivers
### Graphics: 
The graphics drivers are extremely simple as it uses [VGA](https://wiki.osdev.org/VGA_Hardware). To read and write from the screen, A pointer to the video memory is saved and the contents are edited. The screen operates in standard BIOS 80 col mode. All commands are done through the [VGA registers](https://wiki.osdev.org/VGA_Hardware#Port_0x3C4.2C_0x3CE.2C_0x3D4)
### Keyboard:
The keyboard driver is supports all common keyboard interfaces. It access the keyboard through the Programmable Interrupt Controller aka [PIC](https://en.wikipedia.org/wiki/Programmable_interrupt_controller). The commands are the [ISA standard port control commands](https://wiki.osdev.org/Interrupts#Standard_ISA_IRQs).
## Libraries
Many std libs did not work properly when included (especially if using MinGW). Libraries that do not work or have functions that would not work in the custom kernel are edited or rewritten. The functions of these are the same however the implementation is different.
### Known Working STD Libs:
- stdlib.h
- fcntl.h
- unistd.h
- stdbool.h
### Known Non Working STD Libs:
- stdio.h (obviously)
- string.h
### Rewritten STD Libs:
- string.h (excluding error handling, that is soon after the error include files are fully supported)
- stdio.h (excluding file write streams due to no current fs)
## File System
While no FS is currently implemented, the plan is to use FUSE or a simple IDE controller.
# OS
The operating system is passed all the functions from the kernel, just as would happen in a typical microkernel. The OS shares similar functions to MS-DOS and operates similarly to MS-DOS 6.x-7.x
### Supported Commands
- cls: clears screen
- echo \[arg1\]: prints arg1
- exit: end all tasks (basically shutdown)
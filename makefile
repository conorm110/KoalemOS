CC=gcc
KERNEL=kernel.elf
CFLAGS=-m32 -ffreestanding -std=c99 -c
LDFLAGS=-m elf_i386
BUILDDIR=build/
CSOURCES=$(wildcard *.c)
COBJS=$(CSOURCES:.c=.o)
COBJSFULL=$(addprefix $(BUILDDIR), $(CSOURCES:.c=.o))
IDEDRIVE = -device piix3-ide,id=ide -drive id=disk,file=image.img,format=raw,if=none -device ide-hd,drive=disk,bus=ide.0
ATADRIVE = -drive id=disk,file=image.img,if=none -device ahci,id=ahci -device ide-hd,drive=disk,bus=ahci.0
all: build_dir $(KERNEL)

build_dir:
	mkdir -p build

kernel_asm.o: kernel.asm
	nasm -f elf32 kernel.asm -o $(BUILDDIR)kernel_asm.o

.c.o:
	$(CC) $(CFLAGS) $< -o $(BUILDDIR)$@ 

$(KERNEL): kernel_asm.o $(COBJS)
	ld $(LDFLAGS) -T link.ld -o $(BUILDDIR)$(KERNEL) $(BUILDDIR)kernel_asm.o $(COBJSFULL)

clean:
	rm -rf build/

run:
	qemu-img create image.img 10M
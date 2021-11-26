## Booting With Grub
The outputted `kernel.elf` file nativly supports multiboot. This means it works with grub and other handy dandy bootloaders. I use grub because well its easy.

Everything needed to create a bootable iso is located in grubboot/

Once in grubboot, there is a make file. `make` will create the bootable iso and `make clean` will clean the isodir. `koalemos.iso` can now be booted from.
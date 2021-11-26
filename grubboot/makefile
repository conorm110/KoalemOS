all:
	cp ../build/build/kernel.elf .
	mkdir -p isodir/boot/grub
	cp kernel.elf isodir/boot/kernel.elf
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o koalemos.iso isodir

clean:
	rm kernel.elf
	rm -rf isodir/
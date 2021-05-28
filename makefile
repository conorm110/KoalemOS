build:
	nasm boot/bootloader.asm -f bin -o bin/bootloader.bin
	nasm kernel/extendedprogram.asm -f bin -o bin/extendedprogram.bin
	cat "bin/bootloader.bin" "bin/extendedprogram.bin" > "bin/os.flp"
	qemu-system-x86_64 bin/os.flp
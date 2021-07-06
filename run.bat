cd "Sector 1"
nasm bootloader.asm -f bin -o ../bin/bootloader.bin
cd "../"
cd "Sector 2+"
nasm extendedprogram.asm -f bin -o ../bin/extendedprogram.bin
cd "../"
cd bin
copy /b bootloader.bin+extendedprogram.bin bootloader.flp
qemu-system-x86_64 bootloader.flp
cd ../
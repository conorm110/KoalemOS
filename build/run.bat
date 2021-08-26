qemu-img create flp.img 360k
qemu-system-x86_64 -kernel build/kernel.elf -drive file=flp.img,index=1,if=floppy,format=raw
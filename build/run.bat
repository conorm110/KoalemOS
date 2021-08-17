qemu-img create disk.img 10M
qemu-system-i386 -kernel build/kernel-001 -hda disk.img
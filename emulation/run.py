import os
os.remove("sys/dev/flp.img")
cmd = "qemu-system-x86_64 -kernel ../build/build/kernel.elf "
if (input("Floppy Drive y/[n]: ") == "y"): 
    os.system("qemu-img create sys/dev/flp.img " + input("FLP Storage: "))
    cmd += "-drive file=sys/dev/flp.img,index=1,if=floppy,format=raw"

os.system(cmd)
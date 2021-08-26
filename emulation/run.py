import os
import shutil
import platform
import os.path
from os import path

def clean():
    if path.exists("$/"):
        shutil.rmtree("$/")
        return True
    return False

def fs_setup():
    os.mkdir("$/")
    os.mkdir("$/kernel/")
    os.mkdir("$/devices/")
    os.mkdir("$/lib/")
    move_lib()
    shutil.move("../build/build/kernel.elf", "$/kernel/kernel.elf")
    return

def flp_setup(cmd):
    if (input("Floppy Drive y/[n]: ") == "y"): 
        os.system("qemu-img create $/devices/flp.img " + input("FLP Storage: "))
        cmd += "-drive file=$/devices/flp.img,index=1,if=floppy,format=raw"
    return cmd

def build_kernel():
    if (platform.system() == 'Linux'):
        os.system("cd .. && ./build.sh")
        return True
    elif (platform.system() == 'Windows'):
        os.system("cd .. && wsl ./build.sh && cd emulation")
        return True
    else:
        return False

def move_lib():
    os.system("cp ../lib/* $/lib/")
    return

def main():
    cmd = "qemu-system-x86_64 -kernel $/kernel/kernel.elf " # QEMU Base Start Command

    if clean(): 
        if build_kernel():
            fs_setup() # Setup FileSystem
            cmd = flp_setup(cmd) # Setup FLP Drive
            os.system(cmd) # Start VM
        else:
            print("Error: Kernel Could Not Be Created")
            exit()
    else:
        print("Error: Could not remove $/")
        exit()


if __name__ == "__main__":
    main()
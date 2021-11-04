## Building
The system for building and virtuilizing KoalemOS is very janky but it works *relativly* reliably.

Located in the root directory is **build.sh**. Upon first download you need to run 
```
chmod +x ./build.sh
```
**build.sh** cleans the old build directory, creates a new one, and then copies all c, asm, and header files to build/. It then copies **makefile** and **link.ld** into build/. Then it cds into the build directory and runs the makefile to build the kernel and OS. To run build.sh, just run
```
./build.sh
```
The **makefile** is quite simple. It assembles the NASM code, compiles the C code, and links them together with **link.ld**. 
## Running
There are a few options for running KoalemOS. QEMU is reccomended as many of the drivers are developed for QEMU supported devices. It also has a built in bootloader for kernels so we dont have to mess with GRUB or any other bootloader.

There are a few running options depending on your needs. 

`make run_no_disk`: runs kernel in qemu with no disk

`make run_ide`: runs kernel in qemu with 10M ide disk

`make run_sata`: runs kernel in qemu with 10M sata disk

The way to run qemu will change soon as this method does not scale and is very sketchy, sorry 'bout that.

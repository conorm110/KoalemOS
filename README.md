# KoalemOS
## Build and Run
*NOTE: KoalemOS is built and developed on a Windows PC with WSL so both command prompt and WSL Ubuntu are used*

**WSL**
```bash
./build.sh
```
**CMD**
```
cd build
run
```
*NOTE: QEMU is run without WSL due to an issue with Windows 11 WSL for programs with a GUI. If I remember I will switch it back.*
## Kernel
KoalemOS is built on a custom kernel for x86-32. It is Unix-like.
### Driver Support
- Keyboard (US)
- Basic VGA Controller (VESA standard)
### Kernel Support
- x86-32
- AMD 64 (runs in 32 bit mode)
- IDT (Interrupt Descriptor Table)
- VESA VGA (Most graphics controllers support this since ~2004)
## OS
The development of KoalemOS itself is halted while the kernel is being developed. 
### Library Support
A few C libraries have been rewritten for KoalemOS

- stdio.h (non file writing functions)
- string.h (fully stable & complete)

<sub><sup>
Copyright (c) 2021, Conor Mika
All rights reserved.</sup></sub>
## Building
The system for building and virtuilizing KoalemOS is very janky but it works *relativly* reliably.

Please note the building and virtualizing system is designed for windows 10 with WSL (Ubuntu)

All building is done in WSL so it can be easily replicated in any debian based OS. 

To set up the building process, run
```
wsl chmod +x ./build
```

To build without running, run
```
./build
```

To only run virtually, run
```
qemu-system-i386 -kernel build/build/kernel.elf
```

To build and run in vm, run
```
run
```

## Building
The system for building and virtuilizing KoalemOS is very janky but it works *relativly* reliably.

Please note the building and virtualizing system is designed for windows 10 with WSL (Ubuntu)

All building is done in WSL so it can be easily replicated in any debian based OS. 

To build the kernel:
```
cd kernel
make kernel
```

To build the disk image (required for running):
```
cd kernel
make buildimg
```

To run (WINDOWS 10/11)
```
cd kernel
run
```

To run (DEBIAN BASED)
```
cd kernel
make run
```
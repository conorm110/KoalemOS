# KoalemOS
KoalemOS is a super simple OS meant for messing around and seeing how code really interacts with hardware. The tools for building UEFI are from [PonchoOS](https://github.com/Absurdponcho/PonchoOS). The OS is completely different from PonchoOS but all the same build tools are being used because I didnt feel like making my own tbh.

## Building
Everything can be done on basically any linux system or WSL

```
cd kernel
make kernel
make buildimg
```

Replace `make buildimg` with `make buildimgnodd` if you have built it in the same directory before without cleaning, it saves like 10 seconds by skipping a creation task.

## Running
You will need QEMU emulator or you can create a bootable USB
### QEMU
Linux 
```
cd kernel
make run
```

Windows 7+
```
cd kernel
run
```
On some systems replace `run` with `run2`, depends on how your computers feelin'

# OS
## Keyboards
Keyboards are supported through PIC, this works on most modern systems. You can either interface directly with the keyboard handler using `char keyboard_handler()` in `keyboard/keyboard.h` or just interface with `char read_char()` in `keyboard/text_input.h`.

On the todo list is to add more key maps for different languages but for now if you need to edit the keymap just edit `keyboard/keyboard_map.h`.

## KLM String
`klm_string.h` is the equivlent of just the standard string library but remade to fit the OS. It should have similar functionality, as needs for different functions from the standard string library grow, `klm_string.h` will become more complete.

## Graphics
Graphics are just handled through GOP with no graphics card support currently. (Graphics card support likely will not come for a long long while). You can directly edit the framebuffer but everything is meant to be more text-oriented so it is reccomended just to use the functions in `graphics/render_text.h`

## PCI
KoalemOS has support for listing PCI devices and directly reading to and from them. All the functions for these interactions are in `pci/pci.h`.

## CLI
There is a bit of a frame of a terminal like interface for the OS all in `kernel.c`. 
- pci : lists pci devices
- set-background hhhhhhhh : sets background color
  - hhhhhhhh as in a 8 long hex value, ex ff00ff00, value determines color 
- set-foreground hhhhhhhh : sets foreground color
- clear : clear the screen
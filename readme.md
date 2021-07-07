# KoalemOS
KoalemOS is a x86-16 bit OS written in assembly. KoalemOS is named after the Greek daimon of stupidity, Koalemos.
## Version 0.01
- New Kernel
    - VESA BIOS Extensions
        - Text Mode: 80x32 character grid, 2 supported colors
        - VGA Mode: 320p, 16 colors. No shape functions, only allows for drawing pixel by pixel and filling screen
- New Terminal
    - No current commands supported
    - Backspace and special characters not supported
    - Supports text input and enter keypresses
- OS can be run over kernel directly
[org 0x7e00]

jmp extendedprogram

%include "BIOS_VGA/print.asm"
%include "BIOS_VGA/bios_cmd.asm"
%include "VESA/pixel_draw.asm"
%include "VESA/vesa_cmd.asm"
%include "BIOS_Keyboard/keyboard.asm"

sector2entercode:
    db 'Sector 2+ Entered...                                                            ',0

vgaenterbegincode:
    db 'Entering Vesa VGA mode...                                                       ',0

graphicsmodegood:
    db 'Graphics Initialization Complete...                                             ',0

extendedprogram:
    mov  bx, sector2entercode
    call PrintString
    mov  bx, vgaenterbegincode
    call PrintString
    
    ; Enter VESA Bios Graphics
    call entervesavga
    call enterframebuffer

    mov  ax,67 ; Y coord
    mov  bx,112 ; X coord
    call draw_green_pixel

    call entertextmode
    
    mov  bx, sector2entercode
    call PrintString
    mov  bx, vgaenterbegincode
    call PrintString
    mov  bx, graphicsmodegood
    call PrintString

    mov dh, 0x00

    loop:
        mov ah, 0x00       ; tell bios to get current key
        int 0x16           ; activate interupt

        mov bh,ah          ; put keyboard value into upper bh
        call mapChar       ; map keyboard
        mov [Char],bh      ; put bh into char

        mov bx, Char       ; pass char to print
        call PrintString   ; print char
        jmp loop
Char:
    db "f",0

times 1024-($-$$) db 0
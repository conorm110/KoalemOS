entervesavga:
    mov  ax, 13h    ; AH=0 (Change video mode), AL=13h (Mode)
    int  10h        ; Video BIOS interrupt
    ret

enterframebuffer:
    mov  ax, 0A000h ; The offset to video memory
    mov  es, ax     ; We load it to ES through AX, becouse immediate operation is not allowed on ES
    ret

vesacls:
    mov ax, 0
    mov dl,0
    clsloop:
        mov di,ax
        mov [es:di],dl
        inc ax
        cmp ax, 64000
        jne clsloop
    ret
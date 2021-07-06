PrintString:
    push ax
    push bx

    mov ah, 0x0e
    .Loop:
    cmp [bx], byte 0
    je .Exit
        mov al, [bx]
        int 0x10
        inc bx
        jmp .Loop
    .Exit:

    pop ax
    pop bx
    ret

cls:
  pusha
  mov ah, 0x00
  mov al, 0x03  ; text mode 80x25 16 colours
  int 0x10
  popa
  ret

newline:
    mov dl, 0x00
    mov ah, dh
    mov dh, 0x50
    sub dh, ah
    newlineLoop:
        inc dl
        cmp dl, dh
        jl nlSpace
        
    endNLLoop:
        mov dh, 0x00
        ret

nlSpace:
    mov ah, 0x0e
    mov bh, ' '
    mov al, [bx]
    int 0x10
    jmp newlineLoop
; text mode
spacetext:
    mov dx, 0x0
    cmp dx, 0x30
    jle spacebuffer
    ret

spacebuffer:
    mov bx, space
    inc dx
    call PrintString
    cmp dx, 0x206
    jle spacebuffer

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


;; REAL VGA 
; Required to run VGA commands
EnterRealVGA:
    mov ax, 13h
    int 10h
    ret

; clear
clsploop:
    inc bx
    cmp bx, 0x7F80
    jl clsdrawpx
    ret
clsdrawpx:
    mov ax, 0A000h 
    mov es, ax 
    mov ax, bx ;location
    mov di, ax
    mov dx, 0x0d
    mov [es:di], dl 
    jmp clsploop
    ret
clsploc:
    db 0x0
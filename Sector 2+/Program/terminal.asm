terminal:
    mov bx, enterterminalalert
    call PrintString
    mov bx, welcomestring
    call PrintString
    terminal_loop:
        mov ah, 0x00       ; tell bios to get current key
        int 0x16           ; activate interupt

        mov bh,ah          ; put keyboard value into upper bh
        call mapChar       ; map keyboard
        mov [Char],bh      ; put bh into char

        mov bx, Char       ; pass char to print
        call PrintString   ; print char
        jmp terminal_loop
Char:
    db "f",0

enterterminalalert:
    db 'Terminal Entered...                                                             ',0
welcomestring:
    db '                           Welcome to KoalemOS 0.01                             ',0
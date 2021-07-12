osenteralert:
    db 'OS Entered...                                                                   ',0
enteringterminalalert:
    db 'Entering Terminal...                                                            ',0
os_main_func:
    mov  bx, osenteralert
    call PrintString
    mov  bx, enteringterminalalert
    call PrintString
    jmp terminal
    jmp $
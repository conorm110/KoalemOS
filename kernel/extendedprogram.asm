[org 0x7e00]
; VGA Text Mode
call EnterRealVGA
; Real VGA


call spacetext
mov bx, 0x0
call clsdrawpx


mov bx, hw
call PrintString

jmp $


%include "drivers/vesa.asm"
space:
    db ' ',0
hw:
    db 'uwu',0
times 1024-($-$$) db 0
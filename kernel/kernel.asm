bits 32
section .text
align 4
dd 0x1BADB002
dd 0x00
dd - (0x1BADB002 + 0x00) 

global start
global read_port
global write_port
global load_idt
global keyboard_interrupt_handler
global halt_program
extern kmain
extern keyboard_handler

start:
    cli
    call kmain
    hlt

; Read from an IO port
; Argument: Port #
read_port:
    mov edx, [esp + 4]  ; Copy argument (IO port #) from stack to edx register.
                        ; Before a C function calls our assembly code, it pushes
                        ; the function call's arguments to the stack.

    in al, dx           ; Read value on the IO port into AL. Function return
                        ; values are received through the EAX register. AL
                        ; is the lower 8 bits of EAX

    ret                 ; Pass control back to calling C code

; Write value to an IO port
; Argument 1: Port #
; Argument 2: Value
write_port:
    mov edx, [esp + 4]  ; Copy IO port # from stack into edx register
    mov al, [esp + 8]   ; Copy value to write into al
    out dx, al          ; Output value on port
    ret                 ; Return to C

; Load our newly-created IDT
; Argument: Start address of IDT
load_idt:
    mov edx, [esp + 4]
    lidt [edx]
    sti                 ; Turn interrupts back on
    ret

; Handle a keyboard interrupt by calling our C function
keyboard_interrupt_handler:
    ret

halt_program:
    hlt
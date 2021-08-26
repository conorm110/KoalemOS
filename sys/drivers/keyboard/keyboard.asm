extern keyboard_handler
global keyboard_interrupt_handler

; Handle a keyboard interrupt by calling our C function
keyboard_interrupt_handler: ret
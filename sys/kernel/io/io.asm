; Copyright (c) 2021, Conor Mika
; All rights reserved.
; This source code is licensed under the BSD-style license found in the
; LICENSE file in the root directory of this source tree. 

global read_port
global write_port

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
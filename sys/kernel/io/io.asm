; Copyright (c) 2021, Conor Mika
; All rights reserved.
; This source code is licensed under the BSD-style license found in the
; LICENSE file in the root directory of this source tree. 

; Linking
global read_port
global write_port

; read_port(portNum) - reads port
;
; reads portNum port and returns
; port value
; PARAM: Port #
read_port:
    mov edx, [esp + 4]  ; Copy argument (IO port #) from stack to edx register.
    in al, dx           ; Read value on the IO port into AL. 
    ret                 ; Pass control back to calling C code

; write_port(portNum, Value) - writes
; value to port
;
; PARAM: Port #
; PARAM: Value
write_port:
    mov edx, [esp + 4]  ; Copy IO port # from stack into edx register
    mov al, [esp + 8]   ; Copy value to write into al
    out dx, al          ; Output value on port
    ret                 ; Return to C
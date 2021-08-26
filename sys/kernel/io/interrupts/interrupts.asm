; Copyright (c) 2021, Conor Mika
; All rights reserved.
; This source code is licensed under the BSD-style license found in the
; LICENSE file in the root directory of this source tree. 

global load_idt

; load_idt(idt_ptr) - load idt
; 
; loads newly created IDT
; PARAM - idt_ptr:
; start address of IDT
load_idt:
    mov  edx, [esp + 4]
    lidt [edx]
    sti                 ; interrupts on
    ret
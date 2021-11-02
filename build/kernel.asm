; Copyright (c) 2021, Conor Mika
; All rights reserved.
; This source code is licensed under the BSD-style license found in the
; LICENSE file in the root directory of this source tree. 

; NASM setup
bits  32
section .text
align 4

; Multiboot Header (Needed for GRUB)
dd    0x1BADB002
dd    0x00
dd    - (0x1BADB002 + 0x00) 

; Linking
global start
extern kmain

; start() - begin
; 
; NASM/LD entry point
; enters kernel
start:
    cli            ; clear interupt
    call kmain     ; enter kernel
    hlt            ; if somehow kernel finishes execution, halt CPU

; Include all other ASM files
%include "ports.asm"
%include "interrupts.asm"
%include "keyboard.asm"
%include "k_time.asm"
%include "os_functions.asm"
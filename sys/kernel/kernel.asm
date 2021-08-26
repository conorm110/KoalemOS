; Copyright (c) 2021, Conor Mika
; All rights reserved.
; This source code is licensed under the BSD-style license found in the
; LICENSE file in the root directory of this source tree. 

bits  32
section .text
align 4
dd    0x1BADB002
dd    0x00
dd    - (0x1BADB002 + 0x00) 

global start
extern kmain

start:
    cli
    call kmain
    hlt

%include "io.asm"
%include "interrupts.asm"
%include "keyboard.asm"
%include "k_time.asm"
%include "os_functions.asm"


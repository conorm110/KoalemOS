; Copyright (c) 2021, Conor Mika
; All rights reserved.
; This source code is licensed under the BSD-style license found in the
; LICENSE file in the root directory of this source tree. 

; Linking
extern keyboard_handler
global keyboard_interrupt_handler

; keyboard_interrupt_handler() - 
; recurses C function
keyboard_interrupt_handler: ret
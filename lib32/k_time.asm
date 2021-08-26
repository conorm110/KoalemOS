; Copyright (c) 2021, Conor Mika
; All rights reserved.
; This source code is licensed under the BSD-style license found in the
; LICENSE file in the root directory of this source tree. 

global delay_cycle

; delay_cycle: delay one clk
; 
; delays by one CPU cycle (nop)
; DO NOT USE FOR REAL TIMING
; JUST FOR DEBUGGING
delay_cycle:
    nop
    ret
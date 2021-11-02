/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

void init_idt();
extern void keyboard_interrupt_handler();
extern void write_port(int port, int value);
extern int read_port(int port);
extern void load_idt(unsigned long *idt_ptr);
extern void halt_program();
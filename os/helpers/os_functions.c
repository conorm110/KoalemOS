/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "screen.h"
#include "io.h"
#include "os_functions.h"

/**
 * halt_program() - hlt
 * 
 * extern to kernal.asm
 * halt_program which executes
 * hlt command. use for safe
 * termination
 */
extern void halt_program();

/**
 * terminate_os() - terminate os
 * 
 * Disables cursor, clears screen,
 * then halts all programs. Use
 * at end of os_main or other shutdown
 * routes.
 */
void terminate_os() {
    write_port(0x3D4, 0x0A);
	write_port(0x3D5, 0x20);
    cls();
    halt_program();
}

/**
 * clear() - clears screen
 * 
 * Slightly better memory efficiency to
 * call this function then include
 * screen.h and call cls nativly. 
 * 
 * TODO: clear screen in all graphics modes
 * and have efficient clear
 */
void clear() {
    cls();
    return;
}
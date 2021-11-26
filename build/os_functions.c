/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "screen.h"
#include "ports.h"
#include "os_functions.h"
#include "k_stdio.h"
#include "pci.h"

/**
 * haltprogram() - hlt
 * 
 * extern to kernel.asm
 * haltprogram which executes
 * hlt command. use for safe
 * termination
 */
extern void haltprogram();

/**
 * terminate_os() - terminate os
 * 
 * Disables cursor, clears screen,
 * then halts all programs. Use
 * at end of os_main or other shutdown
 * routes.
 */
void termos() {
    write_port(0x3D4, 0x0A);
	write_port(0x3D5, 0x20);
    cls();
    haltprogram();
}

/**
 * clear() - clears screen
 * 
 * Slightly better memory efficiency to
 * call this function then include
 * screen.h and call cls nativly. 
 */
void clear() {
    cls();
    return;
}

/**
 * help - output help 
 * 
 * when called, outputs help menu with all 
 * terminal commands
 */
void help() {
    
    puts("pcilist - list all available PCI devices\n");
    puts("clear - clear the screen\n");
    puts("help - lists all os commands\n");
    puts("echo [arg] - echos argument str to screen\n");
    puts("termos - terminates os\n");
    return;
}

/**
 * pcilist - list pci connections
 * 
 * tests pci and lists out connections
 * and their bus data
 */
void pcilist() {
    puts("\n");
    pci_test();
    puts("\n");
    return;
}

/**
 * echo - echos user
 * 
 * echos string following user 
 * command, takes char *line as a 
 * param
 */
void echo(char *line) {
    line+=5;
    puts(line);
    puts("\n");
    return;
}

/**
 * _cmd_not_found - output warning
 * 
 * outputs warning partaining to not found 
 * terminal command
 */
void _cmd_not_found(char *line) {
    puts("Command '");
    puts(line);
    puts("' not found.\n");
}
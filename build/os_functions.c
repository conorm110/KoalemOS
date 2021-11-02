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
 * halt_program() - hlt
 * 
 * extern to kernal.asm
 * halt_program which executes
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


void help() {
    puts("clear - clear the screen");
    puts("\npcilist - list all available PCI devices");
    puts("\ngetata - scans and initilizes all accesable ata drives");
    puts("\ngetide - scansand initilizes all accesable ide drives");
    puts("\necho [arg] - echos argument str to screen \n");
    return;
}

void pcilist() {
    puts("\n");
    pci_test();
    puts("\n");
    return;
}

void echo(char *line) {
    line+=5;
    puts(line);
    puts("\n");
    return;
}

void cmd_not_found(char *line) {
    puts("Command '");
    puts(line);
    puts("' not found.\n");
}
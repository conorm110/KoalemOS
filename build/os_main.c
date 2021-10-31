/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "k_stdio.h"
#include "k_string.h"
#include "k_time.h"

#include "os_functions.h"
#include "os_helpers.h"

#include "pci.h"

/**
 * os_main() - main os function
 * 
 * called from kernel, all
 * os level programs now return
 * here.
 */
int os_main()
{

    puts("KoalemOS v0.1.0\n");

    while (true)
    {
        puts("> ");
        char *line = gets();
        if(strlen(line) == 7 && strcmp(line, "pcilist")){
            puts("\n");
            pci_test();
            puts("\n");
        } else if (strcmp(line, "clear")) {
            clear();
        } else if (strcmp(line, "help")) {
            puts("\nclear - clear the screen\npcilist - list all available PCI devices\ngetata - scans and initilizes all accesable ata drives\ngetide - scansand initilizes all accesable ide drives\necho [arg] - echos argument str to screen\n");
        } else if(strlen(line) > 6 && !strncmp(line, "echo", 3)) {
            line+=5;
            puts(line);
            puts("\n");
        } else {
            puts("\nCommand '");
            puts(line);
            puts("' not found.\n");
        }
    }
    
    terminate_os();
    return 0;
}
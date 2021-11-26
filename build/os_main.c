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

    puts("KoalemOS v0.1.3\n");

    while (true)
    {
        puts("> ");
        char *line = gets();
        if(strlen(line) == 7 && strcmp(line, "pcilist")){
            pcilist();
        } else if (strcmp(line, "clear")) {
            clear();
        } else if (strcmp(line, "help")) {
            help();
        } else if(strlen(line) > 6 && !strncmp(line, "echo", 3)) {
            echo(line);
        } else if (strlen(line) > 5 && !strncmp(line, "termos", 5)) {
            termos();
        } else {
            _cmd_not_found(line);
        }
    }
    
    termos();
    return 0;
}
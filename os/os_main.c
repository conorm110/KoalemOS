/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "k_stdio.h"
#include "os_functions.h"
#include "k_string.h"
#include "os_helpers.h"
#include "fs.h"
#include "k_time.h"

/**
 * os_main() - main os function
 * 
 * called from kernel, all
 * os level programs now return
 * here.
 */
int os_main()
{
    flp_detect();
    FIS_REG_H2D fis = fs_init();
    //debug_fis(fis);

    puts("KoalemOS v0.0.3\n");
    puts("\n\nPRESS ENTER TO TERMINATE OS");
    char *line = gets();
    terminate_os();
    return 0;
}
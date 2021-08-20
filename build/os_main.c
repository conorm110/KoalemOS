/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "k_stdio.h"

int os_main() {
    // Only for debugging purposes
    puts("KoalemOS v0.0.1\n");
    while(1) {
        puts("> ");
        char *line = gets();
    }
    return 0;
}
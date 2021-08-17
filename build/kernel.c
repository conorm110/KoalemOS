/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "kernel.h"
#include "screen.h"
#include "interrupts.h"

#include "os_main.h"
/**
 * kmain - entry point
 * 
 * Program entry point. Starts up
 * all kernel functions then passes
 * them to the operating system.
 */
void kmain()
{
    init_video();
    init_idt();


    os_main();
}
/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "flp.h"
#include "io.h"
#include "k_stdio.h"

/**
 * flp_detect() - detect floppy drives
 * 
 * outputs the status of flp drives 1
 * and 2 with the specifications of the
 * disk(ette)(s) in the drive
 */
void flp_detect() {
    write_port(0x70, 0x10);
    unsigned drives = read_port(0x71);

    puts(" - Floppy drive 0: ");
    if ((drives >> 4) < 11) {
        puts(drive_types[drives >> 4]);
    } else {
        puts("No FLP drive @ index=0");
    }
    puts("\n\n - Floppy drive 1: ");
    if ((drives & 0xf) < 11) {
        puts(drive_types[drives & 0xf]);
    } else {
        puts("No FLP drive @ index=1");
    }
    puts("\n\n");
    

}
/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "flp.h"
#include "io.h"
#include "k_stdio.h"
#include "k_time.h"

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

void floppy_write_cmd(int base, char cmd) {
    int i; // do timeout, 60 seconds
    for(i = 0; i < 600; i++) {
        delay(30000000);
        if(0x80 & read_port(base+FLOPPY_MSR)) {
            return (void) write_port(base+FLOPPY_FIFO, cmd);
        }
    }
    puts("floppy_write_cmd: timeout");   
}

unsigned char floppy_read_data(int base) {

    int i; // do timeout, 60 seconds
    for(i = 0; i < 600; i++) {
        delay(30000000);
        if(0x80 & read_port(base+FLOPPY_MSR)) {
            return read_port(base+FLOPPY_FIFO);
        }
    }
    puts("floppy_read_data: timeout");
    return 0; // not reached
}
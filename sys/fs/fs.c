/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "fs.h"
#include "k_string.h"
#include "screen.h"
#include "os_helpers.h"
#include "k_stdio.h"

/**
 * fs_init() - issue an ATA Identify command
 * 
 * Issues an ATA Identify command to the
 * device. Constructs FIS.
 */
FIS_REG_H2D fs_init()
{
    FIS_REG_H2D fis;
    memset(&fis, 0, sizeof(FIS_REG_H2D));
    fis.fis_type = FIS_TYPE_REG_H2D;
    fis.command = 0xEC; // 0xEC
    fis.device = 0;     // Master device
    fis.c = 1;          // Write command register
    return fis;
}

/**
 * debug_fis()- debug fs_init()
 * 
 * Prints out all registers in FIS
 * generated from fs_init()
 */
void debug_fis(FIS_REG_H2D fis)
{
    puts("ATA FIS IDENTITY\n");
    char *fis_type;
    itoa(fis.fis_type, fis_type, 16);
    puts("fis_type: 0x");
    puts(fis_type);
    putchar('\n');
    char *pmport;
    itoa(fis.pmport, pmport, 16);
    puts("pmport: 0x");
    puts(pmport);
    putchar('\n');
    char *rsv0;
    itoa(fis.rsv0, rsv0, 16);
    puts("rsv0: 0x");
    puts(rsv0);
    putchar('\n');
    char *c;
    itoa(fis.c, c, 16);
    puts("c: 0x");
    puts(c);
    putchar('\n');
    char *command;
    itoa(fis.command, command, 16);
    puts("command: 0x");
    puts(command);
    putchar('\n');
    char *lba0;
    itoa(fis.lba0, lba0, 2);
    puts("LBA0: 0b");
    puts(lba0);
    putchar('\n');
    char *lba1;
    itoa(fis.lba1, lba1, 2);
    puts("LBA1: 0b");
    puts(lba1);
    putchar('\n');
    char *lba2;
    itoa(fis.lba2, lba2, 2);
    puts("LBA2: 0b");
    puts(lba2);
    putchar('\n');
    char *lba3;
    itoa(fis.lba3, lba3, 2);
    puts("LBA3: 0b");
    puts(lba2);
    putchar('\n');
    char *lba4;
    itoa(fis.lba4, lba4, 2);
    puts("LBA4: 0b");
    puts(lba4);
    putchar('\n');
    char *lba5;
    itoa(fis.lba5, lba5, 2);
    puts("LBA5: 0b");
    puts(lba5);
    putchar('\n');
    char *device;
    itoa(fis.device, device, 16);
    puts("Device: 0x");
    puts(device);
    putchar('\n');
    char *featureh;
    itoa(fis.featureh, featureh, 16);
    puts("featureh: 0x");
    puts(featureh);
    putchar('\n');
    char *featurel;
    itoa(fis.featurel, featurel, 16);
    puts("featurel: 0x");
    puts(featurel);
    putchar('\n');
    char *control;
    itoa(fis.control, control, 16);
    puts("control: 0x");
    puts(control);
    putchar('\n');
    char *icc;
    itoa(fis.icc, icc, 16);
    puts("icc: 0x");
    puts(icc);
    putchar('\n');
    return;
}

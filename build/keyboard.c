/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "keyboard.h"
#include "screen.h"
#include "keyboard_map.h"
#include "io.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

/**
 *  init_keyboard - starts keyboard interface
 *
 * Allows for keyboard inturupt in x86 32 bit 
 * protected mode. Supports USB, PS2, and all
 * other common keyboard interfaces.
 */
void init_keyboard()
{
    write_port(0x21, 0xFD);
}

/**
 * keyboard_handler - immediatly read keyboard
 * 
 * Detects any current/active keyboard inputs 
 * Limited to keyboard_map.h size
 */
char keyboard_handler()
{
    unsigned char status;
    char key_code;
    write_port(0x20, 0x20); // Write End of Interrupt (EOI) to PIC
    status = read_port(KEYBOARD_STATUS_PORT);
    if (status & 0x01)
    {
        key_code = read_port(KEYBOARD_DATA_PORT);
        if (key_code < 0)
            return 0;
        return (keyboard_map[key_code]);
    }
    return 0;
}

/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "screen.h"
#include "io.h"

int cursorX = 0;
int cursorY = 0;

char attr = 0x0F;

/**
 * cls - clear the screen
 * 
 * Go through vram setting every byte
 * to the space value.
 */
void cls()
{
    for (int i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT * 2); i += 2)
    {
        move_hw_cursor(0, 0);
        vidptr[i] = ' ';
        vidptr[i + 1] = attr;
    }
}

/**
 * scroll_up - scroll up by 1 row
 * 
 * shift all chars up one row then clear
 * the last row.
 */
void scroll_up()
{
    int last_row_start = (SCREEN_WIDTH * (SCREEN_HEIGHT - 1) * 2);
    for (int pos = SCREEN_WIDTH; pos < (SCREEN_WIDTH * SCREEN_HEIGHT * 2); pos++)
    {
        vidptr[pos - SCREEN_WIDTH * 2] = vidptr[pos];
    }
    for (int pos = last_row_start; pos < (SCREEN_WIDTH * SCREEN_HEIGHT * 2); pos += 2)
    {
        vidptr[pos] = ' ';
    }
}

/**
 * move_hw_cursor - moves the hw cursor
 * 
 * move the hw cursor to location (x,y)
 * by using BIOS VGA commands.
 */
void move_hw_cursor(int x, int y)
{
    unsigned short position = (y * 80) + x;
    cursorX = x;
    cursorY = y;
    write_port(0x3D4, 0x0F);
    write_port(0x3D5, (unsigned char)(position & 0xFF));
    write_port(0x3D4, 0x0E);
    write_port(0x3D5, (unsigned char)((position >> 8) & 0xFF));
}

/**
 * init_video - initialize VGA graphics
 * 
 * set vidptr to beginning of character 
 * graphics mode
 */
void init_video()
{
    vidptr = (unsigned char *)0xB8000;
    cls();
}

/**
 * disable_cursor - disable hw cursor
 * 
 * Use vesa commands to turn off hw
 * cursor
 */
void disable_cursor()
{
    write_port(0x3D4, 0x0A);
    write_port(0x3D5, 0x20);
}

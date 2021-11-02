/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "k_stdio.h"
#include "keyboard.h"
#include "screen.h"

// TODO: printf()
// TODO: sprintf()
// TODO: vprintf()
// TODO: vsprintf()
// TODO: scanf()
// TODO: sscan()

/**
 * getchar() - get next char
 * 
 * Keep checking keyboard input until 
 * valid character recieved. Return
 * said character. 
 */
char getchar()
{
    while (1)
    {
        char cChar = keyboard_handler();
        if (cChar != 0)
        {
            return cChar;
        }
    }
}

/**
 * gets - get string
 * 
 * Get the next line as string and
 * return said string.
 */
char *gets()
{
    char *line;

    for (int i = 0; i < 128; i++)
    {
        int charFound = 0;
        while (charFound == 0)
        {
            char cChar = keyboard_handler();
            if (cChar != 0)
            {
                line[i] = cChar;
                putchar(cChar);
                charFound = 1;
            }
        }
        if (line[i] == '\n')
        {
            line[i] = '\0';
            return line;
        }
    }
    return line;
}


/**
 * putchar - prints char
 * 
 * Prints char to screen. checks if
 * end of line or end of screen and
 * scrolls/enters new line.
 */
void putchar(unsigned char c)
{
    unsigned int location;

    if (c == '\b')
    {
        if (cursorX != 0)
            cursorX--;
    }
    else if (c == '\r')
    {
        cursorX = 0;
    }
    else if (c == '\n')
    {
        cursorX = 0;
        cursorY++;
    }
    else if (c >= ' ')
    {
        location = ((cursorY * SCREEN_WIDTH) + cursorX) * 2;
        vidptr[location] = c;
        vidptr[location + 1] = attr;
        cursorX++;
    }
    if (cursorX >= SCREEN_WIDTH)
    {
        cursorX = 0;
        cursorY++;
    }
    if (cursorY >= SCREEN_HEIGHT)
    {
        cursorY = SCREEN_HEIGHT - 1;
        scroll_up();
    }
    move_hw_cursor(cursorX, cursorY);
}

/**
 * puts - print string
 * 
 * Loops putchar through char[]
 * untill full char[] is printed.
 */
void puts(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        putchar(str[i]);
        i++;
    }
}

// TODO: perror()

/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "textio.h"
#include "../keyboard/keyboard.h"

unsigned int backgroundColor = 0x00000000;
unsigned int foregroundColor = 0xffffffff;

void putChar(unsigned int color, char chr, unsigned int xOff, unsigned int yOff)
{
    unsigned int *pixPtr = (unsigned int *)framebuffer->BaseAddress;
    char *fontPtr = psf1_font->glyphBuffer + (chr * psf1_font->psf1_Header->charsize);
    for (unsigned long y = yOff; y < yOff + 16; y++)
    {
        for (unsigned long x = xOff; x < xOff + 8; x++)
        {
            if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0)
            {
                *(unsigned int *)(pixPtr + x + (y * framebuffer->PixelsPerScanLine)) = color;
            }
        }
        fontPtr++;
    }
}

void puts(unsigned int color, char *str)
{

    char *chr = str;
    while (*chr != 0)
    {
        putChar(color, *chr, CursorPosition.X, CursorPosition.Y);
        CursorPosition.X += 8;
        if (CursorPosition.X + 8 > framebuffer->Width)
        {
            CursorPosition.X = 0;
            CursorPosition.Y += 16;
        }
        chr++;
    }
}

void clearScreen(unsigned int color)
{
    CursorPosition.X = 0;
    CursorPosition.Y = 0;
    while (CursorPosition.Y < framebuffer->Height)
    {
        putChar(backgroundColor, 0xDB, CursorPosition.X, CursorPosition.Y);
        CursorPosition.X += 4;
        if (CursorPosition.X + 4 > framebuffer->Width)
        {
            CursorPosition.X = 0;
            CursorPosition.Y += 16;
        }
    }
    CursorPosition.X = 0;
    CursorPosition.Y = 0;
}

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
                putChar(foregroundColor, cChar, CursorPosition.X, CursorPosition.Y);
                CursorPosition.X += 8;
                charFound = 1;
            }
        }
        if (line[i] == '\n')
        {
            line[i] = '\0';
            backspace(backgroundColor);
            return line;
        }
    }
    return line;
}

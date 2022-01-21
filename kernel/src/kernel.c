/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "ports/ports.h"
#include "keyboard/keyboard.h"
#include "io/textio.h"
#include "lib/string.h"
#include "pci/pci.h"

#include <stdbool.h>

void _start(Framebuffer *framebuffer_r, PSF1_FONT *psf1_font_r)
{
    framebuffer = framebuffer_r;
    psf1_font = psf1_font_r;

    init_keyboard();
    clearScreen();
    puts("KoalemOS v0.0.2 (UEFI)");
    CursorPosition.Y += 16;
    CursorPosition.X = 0;
    puts(">>> ");

    while (1)
    {
        char *c = gets();
        CursorPosition.Y += 16;
        CursorPosition.X = 0;
        if (c[0] == 'e' && c[1] == 'c' && c[2] == 'h' && c[3] == 'o' && c[4] == ' ')
        {
            c += 5;
            puts(c);
            CursorPosition.Y += 16;
            CursorPosition.X = 0;
        }
        else if (c[0] == 'h' && c[1] == 'e' && c[2] == 'l' && c[3] == 'p')
        {
            puts("clear - clears all graphics from screen");
            CursorPosition.Y += 16;
            CursorPosition.X = 0;
            puts("echo [arg] - prints [arg] to screen");
            CursorPosition.Y += 16;
            CursorPosition.X = 0;
            puts("help - prints list of commands");
            CursorPosition.Y += 16;
            CursorPosition.X = 0;
            puts("pci [arg] - interact with pci, type pci help for pci command list");
            CursorPosition.Y += 16;
            CursorPosition.X = 0;
        }
        else if (c[0] == 'c' && c[1] == 'l' && c[2] == 'e' && c[3] == 'a' && c[4] == 'r')
        {
            clearScreen();
            CursorPosition.Y = 0;
            CursorPosition.X = 0;
        }
        else if (c[0] == 'p' && c[1] == 'c' && c[2] == 'i' && c[3] == ' ')
        {
            c += 4;
            if (c[0] == 'd' && c[1] == 'e' && c[2] == 'b' && c[3] == 'u' && c[4] == 'g')
            {
                test_pci();
                CursorPosition.Y += 16;
                CursorPosition.X = 0;
            }
            else if (c[0] == 'h' && c[1] == 'e' && c[2] == 'l' && c[3] == 'p')
            {
                puts("pci debug - lists all pci devices");
                CursorPosition.Y += 16;
                CursorPosition.X = 0;
                puts("pci help - prints list of commands");
                CursorPosition.Y += 16;
                CursorPosition.X = 0;
            }
            else
            {
                puts("ArgErr: \"");
                puts(c);
                puts("\" undefined (most recent call). Type pci help for list of commands.");
                CursorPosition.Y += 16;
                CursorPosition.X = 0;
            }
        }
        else
        {
            puts("CmdErr: \"");
            puts(c);
            puts("\" undefined (most recent call). Type help for list of commands.");
            CursorPosition.Y += 16;
            CursorPosition.X = 0;
        }

        puts(">>> ");
    }

    return;
}
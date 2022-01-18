/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "ports/ports.h"
#include "keyboard/keyboard.h"
#include "io/textio.h"

void _start(Framebuffer *framebuffer_r, PSF1_FONT *psf1_font_r)
{
    framebuffer = framebuffer_r;
    psf1_font = psf1_font_r;

    init_keyboard();
    clearScreen(getBackgroundColor());

    while (1)
    {
        gets();
        CursorPosition.Y += 16;
        CursorPosition.X = 0;
    }

    return;
}
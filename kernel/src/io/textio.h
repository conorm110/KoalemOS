/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

typedef unsigned long long size_t;

typedef struct
{
	void *BaseAddress;
	size_t BufferSize;
	unsigned int Width;
	unsigned int Height;
	unsigned int PixelsPerScanLine;
} Framebuffer;

typedef struct
{
	unsigned char magic[2];
	unsigned char mode;
	unsigned char charsize;
} PSF1_HEADER;

typedef struct
{
	PSF1_HEADER *psf1_Header;
	void *glyphBuffer;
} PSF1_FONT;

typedef struct
{
	unsigned int X;
	unsigned int Y;
} Point;

Point CursorPosition;
Framebuffer *framebuffer;
PSF1_FONT *psf1_font;

void putChar(unsigned int colour, char chr, unsigned int xOff, unsigned int yOff);
void puts(unsigned int colour, char *str);
void clearScreen(unsigned int color);
char *gets();
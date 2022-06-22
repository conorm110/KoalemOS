/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */


typedef struct
{
	void *BaseAddress;
	unsigned long long BufferSize;
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

struct Point
{
	unsigned int X;
	unsigned int Y;
};

struct Point CursorPosition;

Framebuffer *framebuffer;
PSF1_FONT *psf1_font;

void editBackgroundColor(unsigned int color);
void editForegroundColor(unsigned int color);
unsigned int getBackgroundColor();
unsigned int getForegroundColor();

void putChar(unsigned int color, char chr, unsigned int xOff, unsigned int yOff);
void puts(char *str);
void clearScreen();
char *gets();
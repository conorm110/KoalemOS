#include <stddef.h>
#include <stdint.h>
#include "render_text.h"
#include "../lib/klm_string.h"

struct Framebuffer{
	void* BaseAddress;
	size_t BufferSize;
	unsigned int Width;
	unsigned int Height;
	unsigned int PixelsPerScanLine;
};
extern struct Framebuffer klm_framebuffer;
struct PSF1_HEADER{
	unsigned char magic[2];
	unsigned char mode;
	unsigned char charsize;
};
struct PSF1_FONT {
	struct PSF1_HEADER* psf1_Header;

	void* glyphBuffer;
};
extern struct PSF1_FONT klm_psf1_font;

struct Point {
    unsigned int x;
    unsigned int y;
};
extern struct Point klm_cursor;

struct Theme {
    unsigned int foreground;
    unsigned int background;
} klm_theme;

void place_char(char chr, unsigned int xOff, unsigned int yOff)
{
    unsigned int* pixPtr = (unsigned int*)klm_framebuffer.BaseAddress;
    char* fontPtr = klm_psf1_font.glyphBuffer + (chr * klm_psf1_font.psf1_Header->charsize);
    for (unsigned long y = yOff; y < yOff + 16; y++){
        for (unsigned long x = xOff; x < xOff+8; x++){
            if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0){
                    *(unsigned int*)(pixPtr + x + (y * klm_framebuffer.PixelsPerScanLine)) = klm_theme.foreground;
                }else {
                        *(unsigned int*)(pixPtr + x + (y * klm_framebuffer.PixelsPerScanLine)) = klm_theme.background;
                    }

        }
        fontPtr++;
    }
}

void print_char(char chr)
{
    if (chr != '\n' && chr != '\b')
    {
        unsigned int* pixPtr = (unsigned int*)klm_framebuffer.BaseAddress;
        char* fontPtr = klm_psf1_font.glyphBuffer + (chr * klm_psf1_font.psf1_Header->charsize);
        for (unsigned long y = klm_cursor.y; y < klm_cursor.y + 16; y++){
            for (unsigned long x = klm_cursor.x; x < klm_cursor.x+8; x++){
                if ((*fontPtr & (0b10000000 >> (x - klm_cursor.x))) > 0){
                        *(unsigned int*)(pixPtr + x + (y * klm_framebuffer.PixelsPerScanLine)) = klm_theme.foreground;
                    } else {
                        *(unsigned int*)(pixPtr + x + (y * klm_framebuffer.PixelsPerScanLine)) = klm_theme.background;
                    }

            }
            fontPtr++;
        }
        klm_cursor.x+=8;
        if(klm_cursor.x + 8 > klm_framebuffer.Width)
        {
            klm_cursor.x = 0;
            klm_cursor.y += 16;
        }
    }
    else if (chr == '\n')
    {
        klm_cursor.x = 0;
        klm_cursor.y = klm_cursor.y + 16;
    }
    else if (chr == '\b')
    {
        if (klm_cursor.x != 0)
        {
            klm_cursor.x = klm_cursor.x - 8;
            unsigned int* pixPtr = (unsigned int*)klm_framebuffer.BaseAddress;
            for (unsigned long y = klm_cursor.y; y < klm_cursor.y + 16; y++){
                for (unsigned long x = klm_cursor.x; x < klm_cursor.x+8; x++){
                    *(unsigned int*)(pixPtr + x + (y * klm_framebuffer.PixelsPerScanLine)) = 0;
                }
            }
        }
        else
        {
            klm_cursor.y = klm_cursor.y - 16;
            klm_cursor.x = klm_framebuffer.Width-8;
            // TODO: Dont delete until character is present
            print_char('\b');

        }
        
    }
}

void print_str(char* str)
{
    
    char* chr = str;
    while(*chr != 0){
        place_char(*chr, klm_cursor.x, klm_cursor.y);
        klm_cursor.x+=8;
        if(klm_cursor.x + 8 > klm_framebuffer.Width)
        {
            klm_cursor.x = 0;
            klm_cursor.y += 16;
        }
        chr++;
    }
}

void place_str(char* str, unsigned int xOff, unsigned int yOff)
{
    int old_x = klm_cursor.x;
    int old_y = klm_cursor.y;
    klm_cursor.x = xOff;
    klm_cursor.y = yOff;
    char* chr = str;
    while(*chr != 0){
        place_char(*chr, klm_cursor.x, klm_cursor.y);
        klm_cursor.x+=8;
        if(klm_cursor.x + 8 > klm_framebuffer.Width)
        {
            klm_cursor.x = 0;
            klm_cursor.y += 16;
        }
        chr++;
    }
    klm_cursor.x = old_x;
    klm_cursor.y = old_y;
}

void print_int(int n, int base) 
{
    char* buffer;
    itoa(n, buffer, base);
    print_str(buffer);
    return;
}

void print_nl() {
    klm_cursor.x = 0;
    klm_cursor.y += 16;
    return;
}

void set_cursor_x(int n)
{
    klm_cursor.x = n;
    return;
}
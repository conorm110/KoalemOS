#include <stddef.h>
#include <stdint.h>

struct Framebuffer{
	void* BaseAddress;
	size_t BufferSize;
	unsigned int Width;
	unsigned int Height;
	unsigned int PixelsPerScanLine;
} klm_framebuffer;

typedef struct {
	unsigned char magic[2];
	unsigned char mode;
	unsigned char charsize;
} PSF1_HEADER;

struct PSF1_FONT {
	PSF1_HEADER* psf1_Header;
	void* glyphBuffer;
} klm_psf1_font;

struct Point {
    unsigned int x;
    unsigned int y;
} klm_cursor;
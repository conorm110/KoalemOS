struct Framebuffer{
	void* BaseAddress;
	size_t BufferSize;
	unsigned int Width;
	unsigned int Height;
	unsigned int PixelsPerScanLine;
};
struct EFI_MEMORY_DESCRIPTOR {
	uint32_t type;
	uint64_t PhysicalStart;
	uint64_t VisualStart;
	uint64_t NumberOfPages;
	uint64_t Attribute;
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
typedef struct {
	struct Framebuffer* framebuffer;
	struct PSF1_FONT* psf1_Font;
	struct EFI_MEMORY_DESCRIPTOR mMap;
	uint64_t mMapSize;
	uint64_t mMapDescSize;
} BootInfo;

struct Point {
    unsigned int x;
    unsigned int y;
};
extern struct Point klm_cursor;
struct Theme {
    unsigned int foreground;
    unsigned int background;
};
extern struct Theme klm_theme;

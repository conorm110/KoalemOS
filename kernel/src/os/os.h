void os_main();

extern void puts(char *str);
extern char *gets();
extern void clearScreen();
extern void test_pci();
extern void port_word_out(unsigned short port, unsigned short data);
extern void init_keyboard();
extern int strlen(const char *str);

struct Point
{
	unsigned int X;
	unsigned int Y;
};

extern struct Point CursorPosition;
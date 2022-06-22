#include "os.h"

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

void os_main() {
    init_keyboard();
    clearScreen();
    puts("KoalemOS v0.0.3 (UEFI)");
    CursorPosition.Y += 16;
    CursorPosition.X = 0;
    puts(">>> ");

    while (1)
    {
        char *c = gets();
        CursorPosition.Y += 16;
        CursorPosition.X = 0;
        if (c[0] == 'e' && c[1] == 'c' && c[2] == 'h' && c[3] == 'o')
        {
            if (strlen(c) < 6)
            {
                puts("ArgErr: (most recent call) insufficiend arg length. Type help for list of commands.");
            }
            else
            {
                c += 5;
                puts(c);
            }
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
            puts("pci [arg] - interact with pci, type pci -h for pci command list");
            CursorPosition.Y += 16;
            CursorPosition.X = 0;
            puts("pwr [arg] - power options for os, type pwr -h for pwr command list");
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
            if (c[0] == '-' && c[1] == 'd')
            {
                test_pci();
                CursorPosition.Y += 16;
                CursorPosition.X = 0;
            }
            else if (c[0] == '-' && c[1] == 'h')
            {
                puts("pci -d - lists all pci devices");
                CursorPosition.Y += 16;
                CursorPosition.X = 0;
                puts("pci -h - prints list of commands");
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
        else if (c[0] == 'p' && c[1] == 'w' && c[2] == 'r')
        {
            c += 4;
            if (c[0] == '-')
            {
                c += 1;
                if (c[0] == 'v')
                {
                    port_word_out(0x604, 0x2000);  // QEMU (NEW)
                    port_word_out(0xB004, 0x2000); // QEMU < 2.0 / BOCHS
                    port_word_out(0x4004, 0x3400); // VirtualBox
                }
                else if (c[0] == 'h')
                {
                    puts("pwr -v - power off virtual machine");
                    CursorPosition.Y += 16;
                    CursorPosition.X = 0;
                    puts("pwr -h - get list of pwr args");
                    CursorPosition.Y += 16;
                    CursorPosition.X = 0;
                }
                else
                {
                    puts("ArgErr: \"");
                    puts(c);
                    puts("\" is not a valid arg. (most recent call). Type pwr -h for list of commands.");
                    CursorPosition.Y += 16;
                    CursorPosition.X = 0;
                }
            }
            else
            {
                puts("ArgErr: Invalid argument syntax (most recent call). Type pwr -h for list of commands.");
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
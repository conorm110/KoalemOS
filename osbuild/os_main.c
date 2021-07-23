#include "os_main.h"
#include "kernel.h"
#include "screen.h"
#include "terminal_helpers.h"
#include "k_string.h"
#include "k_stdio.h"


/**
 * os_main - main os loop
 * 
 * all programs run from here. runs
 * on top of microkernel
 */
void os_main()
{
    puts("_KoalemOS\n~/>");

    while (1)
    {
        char *line = gets();
        if (strcmp(line, "cls"))
        {
            cls();
            puts("~/>");
        }
        else if (memcmp((int)(line), (int)("echo"), 4) == 0)
        {
            puts(remove_first_chars(line, 5));
            puts("\n~/>");
        }
        else
        {
            puts("Unknown command: ");
            puts(line);
            puts("\n~/>");
        }
    }
    return;
}
#include "terminal_helpers.h"

/**
 * remove_first_chars - removes first n chars
 * 
 * moves ptr to str n bytes after original
 * ptr to remove first n chars
 */
char *remove_first_chars(char s1[], int n)
{
    char *s2 = s1 + n;
    return s2;
}

/**
 * shutdown - terminate all tasks
 * 
 * clears vram, disables cursor, and
 * stops all current tasks
 */
void shutdown()
{
    cls();
    disable_cursor();
    halt_program();
}
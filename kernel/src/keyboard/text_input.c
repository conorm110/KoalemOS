#include "text_input.h"
#include "keyboard.h"

char read_char()
{
    while (1)
    {
        char cChar = keyboard_handler();
        if (cChar != 0)
        {
            return cChar;
        }
    }
}

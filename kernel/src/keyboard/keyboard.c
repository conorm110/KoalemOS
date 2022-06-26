#include "keyboard.h"
#include "keyboard_map.h"
#include "../port/port.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

/**
 *  init_keyboard - starts keyboard interface
 *
 * Allows for keyboard inturupt in x86 32 bit 
 * protected mode. Supports USB, PS2, and all
 * other common keyboard interfaces.
 */
void init_keyboard()
{
    port_byte_out(0x21, 0xFD);
}

/**
 * keyboard_handler - immediatly read keyboard
 * 
 * Detects any current/active keyboard inputs 
 * Limited to keyboard_map.h size
 */
char keyboard_handler()
{
    unsigned char status;
    char key_code;
    port_byte_out(0x20, 0x20); // Write End of Interrupt (EOI) to PIC
    status = port_byte_in(KEYBOARD_STATUS_PORT);
    if (status & 0x01)
    {
        key_code = port_byte_in(KEYBOARD_DATA_PORT);
        if (key_code < 0)
            return 0;
        return (keyboard_map[key_code]);
    }
    return 0;
}

#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "graphics/render_text.h"
#include "keyboard/text_input.h"
#include "lib/klm_string.h"
#include "pci/pci.h"

void klm_terminal()
{
    print_nl();
    print_str(">>> ");
    char buffer[128];
    int i = 0;
    while (1)
    {
        char current_char = read_char();
        if (current_char != '\n' && current_char!= '\b')
        {
            buffer[i] = current_char;
            print_char(current_char);
            i++;
        }
        else if (current_char == '\n')
        {
            buffer[i] == '\0';
            print_nl();


            
            if (strncmp(buffer, "pci", 3))
            {
                test_pci();
            }
            else
            {
                print_str("-bash: ");
                print_str(buffer);
                print_str(": command not found");
            }


            i = 0;
            for (int j = 0; j < 128; j++)
            {
                buffer[j] = '\0';
            }
            klm_terminal();
        }
        else if (current_char == '\b')
        {
            i--;
            print_char('\b');
        }
    }
}

void _start(BootInfo* boot_info){
    klm_framebuffer = *boot_info->framebuffer;
    klm_psf1_font = *boot_info->psf1_Font;
    klm_cursor.x = 0;
    klm_cursor.y = 0;
    klm_theme.foreground = 0xffffffff;
    klm_theme.background = 0x00000000;
    
    
    print_str("Kernel Loaded!");
    
    klm_terminal();

    return;
}
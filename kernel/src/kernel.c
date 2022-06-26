
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "graphics/render_text.h"
#include "keyboard/text_input.h"
#include "lib/klm_string.h"
#include "pci/pci.h"


void _start(BootInfo* boot_info){
    klm_framebuffer = *boot_info->framebuffer;
    klm_psf1_font = *boot_info->psf1_Font;
    klm_cursor.x = 0;
    klm_cursor.y = 0;
    klm_theme.foreground = 0xffffffff;
    klm_theme.background = 0x00000000;
    
    
    print_str("Kernel Loaded!");
    print_nl();
    
    print_str(">>> ");
    while (1) 
    {
        char c0 = read_char();
        print_char(c0);
        if (c0 == 'p')
        {
            char c1 = read_char();
            print_char(c1);
            if (c1 == 'c')
            {
                char c2 = read_char();
                print_char(c2);
                if (c2 == 'i')
                {
                    char c3 = read_char();
                    print_char(c3);
                    if (c3 == '\n')
                    {
                        test_pci();
                        print_str(">>> ");
                    }
                }
                else if(c2=='\n'){print_str(">>> ");}
            }
            else if(c1=='\n'){print_str(">>> ");}
        }
        else if(c0=='\n'){print_str(">>> ");}
    }
    

    return;
}
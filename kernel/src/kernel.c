
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "kernel.h"
#include "graphics/render_text.h"
#include "keyboard/text_input.h"
#include "lib/klm_string.h"
#include "pci/pci.h"



int power (int a, int b)
{
  int out = 1;
  for (int i = 0; i < b; i++)
    {
      out*=a;
    }
  return out;
}
unsigned int str_to_hex(char* str)
{
    
    int len = strlen(str);
    int out = 0;
    for (int i = len; i >= 0 ; i--)
    {
        if (str[len-1-i] == '1') {
            out += (1 * power(16, i));
        } else if (str[len-1-i] == '2') {
            out += (2 * power(16, i));
        } else if (str[len-1-i] == '3') {
            out += (3 * power(16, i));
        } else if (str[len-1-i] == '4') {
            out += (4 * power(16, i));
        } else if (str[len-1-i] == '5') {
            out += (5 * power(16, i));
        } else if (str[len-1-i] == '6') {
            out += (6 * power(16, i));
        } else if (str[len-1-i] == '7') {
            out += (7 * power(16, i));
        } else if (str[len-1-i] == '8') {
            out += (8 * power(16, i));
        } else if (str[len-1-i] == '9') {
            out += (9 * power(16, i));
        } else if (str[len-1-i] == 'a') {
            out += (10 * power(16, i));
        } else if (str[len-1-i] == 'b') {
            out += (11 * power(16, i));
        } else if (str[len-1-i] == 'c') {
            out += (12 * power(16, i));
        } else if (str[len-1-i] == 'd') {
            out += (13 * power(16, i));
        } else if (str[len-1-i] == 'e') {
            out += (14 * power(16, i));
        } else if (str[len-1-i] == 'f') {
            out += (15 * power(16, i));
        } 
    }
    return out;
}

void klm_terminal()
{
    // i am truely sorry for the next line of code, it was written at 3am and quite frankly i cant think of any reason to make it better
    char buffer[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    print_nl();
    print_str(">>> ");
    int i = 0;
    while (1)
    {
        char current_char = read_char();
        if (current_char != '\n' && current_char!= '\b' && current_char != '\t')
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
            else if (strncmp(buffer, "clear", 5))
            {
                clear();
            }
            else if (strncmp(buffer, "set-background", 13))
            {
                unsigned int old_color = get_background();
                char* buffer_copy = buffer;
                buffer_copy += 14;
                set_background(str_to_hex(buffer_copy));
                clear();
                print_str("PRESS [y] TO CONFIRM COLOR");
                print_nl();
                print_str(">>> ");
                char confirm_char = read_char();
                print_char(confirm_char);
                if (confirm_char != 'y')
                {
                    set_background(old_color);
                    clear();
                }
            }
            else if (strncmp(buffer, "set-foreground", 13))
            {
                unsigned int old_color = get_foreground();
                char* buffer_copy = buffer;
                buffer_copy += 14;
                set_foreground(str_to_hex(buffer_copy));
                clear();
                print_str("PRESS [y] TO CONFIRM COLOR");
                print_nl();
                print_str(">>> ");
                char confirm_char = read_char();
                print_char(confirm_char);
                if (confirm_char != 'y')
                {
                    set_foreground(old_color);
                    clear();
                }
            }
            else
            {
                print_str("-bash: ");
                print_str(buffer);
                print_str(": command not found");
            }


            i = 0;
            klm_terminal();
        }
        else if (current_char == '\b')
        {
            i--;
            print_char('\b');
        }
        else if (current_char == '\t')
        {
            clear();
            print_str(">>> ");
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
    
    clear();
    print_str("KoalemOS v0.1.0");
    
    klm_terminal();

    return;
}
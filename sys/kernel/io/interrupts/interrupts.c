#include "interrupts.h"
#include "keyboard.h"

#define IDT_SIZE 256

/**
 * IDT_entry - simple struct for entering IDT
 */
typedef struct IDT_entry
{
    unsigned short int offset_low;
    unsigned short int selector;
    unsigned char zero;
    unsigned char type_attr;
    unsigned short int offset_high;
} IDT_entry;

struct IDT_entry IDT[IDT_SIZE];

/**
 * init_idt - start interupt descriptor table
 * 
 * Allows for use of interupts through the
 * Programmable Interface Controller. Lets
 * us use keyboard, IDE drives, mouse, etc.
 */
void init_idt()
{
    unsigned long keyboard_address;
    unsigned long idt_address;
    unsigned long idt_ptr[2];

    keyboard_address = (unsigned long)keyboard_interrupt_handler;
    IDT[0x21].offset_low = keyboard_address & 0xffff;
    IDT[0x21].selector = 0x08;
    IDT[0x21].zero = 0;
    IDT[0x21].type_attr = 0x8e;
    IDT[0x21].offset_high = (keyboard_address & 0xffff0000) >> 16;
    write_port(0x20, 0x11);
    write_port(0xA0, 0x11);
    write_port(0x21, 0x20);
    write_port(0xA1, 0x28);
    write_port(0x21, 0x00);
    write_port(0xA1, 0x00);
    write_port(0x21, 0x01);
    write_port(0xA1, 0x01);
    write_port(0x21, 0xff);
    write_port(0xA1, 0xff);

    idt_address = (unsigned long)IDT;
    idt_ptr[0] = (sizeof(struct IDT_entry) * IDT_SIZE) + ((idt_address & 0xffff) << 16);
    idt_ptr[1] = idt_address >> 16;

    load_idt(idt_ptr);
    init_keyboard();
}

#include "kernel.h"
#include "screen.h"
#include "interrupts.h"
#include "os_main.h"

/**
 * kmain - entry point
 * 
 * Program entry point. Starts up
 * all kernel functions then passes
 * them to the operating system.
 */
void kmain()
{
    init_video();
    init_idt();
    os_main();
}
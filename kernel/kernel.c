#include "kernel.h"
#include "screen.h"
#include "interrupts.h"
#include "keyboard.h"
#include "k_string.h"
#include "k_stdio.h"
#include "os_main.h"


#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void kmain()
{
    init_video();
    init_idt();
    os_main();
}

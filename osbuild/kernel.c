#include "kernel.h"
#include "screen.h"
#include "interrupts.h"
#include "keyboard.h"
#include "k_string.h"
#include "k_stdio.h"

#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void kmain() {
    init_video();
    init_idt();
    puts("KoalemOS\n~/>");

    while (1) {
        char *line = gets();
        if (strcmp(line, "cls")) {
            cls();
            move_hw_cursor(0, 0);
            puts("~/>");
        } else if (memcmp((int)(line), (int)("echo"), 4) == 0) {
            puts(remove_first_chars(line, 5));
            puts("\n~/>");
        } else {
            puts("Unknown command: ");
            puts(line);
            puts("\n~/>");
        }
    }
}

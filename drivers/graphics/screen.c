#include "screen.h"
#include "io.h"



int cursorX = 0;
int cursorY = 0;

char attr = 0x0F;

/**
 * Clear the screen
 */
void cls() {
    for (int i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT * 2); i += 2) {
        vidptr[i] = ' ';
        vidptr[i + 1] = attr;
    }
}





/**
 * Scroll the screen up by one row
 */
void scroll_up() {
    int last_row_start = (SCREEN_WIDTH * (SCREEN_HEIGHT - 1) * 2);

    // Shift characters and their attributes up a single row
    for (int pos = SCREEN_WIDTH; pos < (SCREEN_WIDTH * SCREEN_HEIGHT * 2); pos++) {
        vidptr[pos - SCREEN_WIDTH * 2] = vidptr[pos];
    }

    // Clear the last row
    for (int pos = last_row_start; pos < (SCREEN_WIDTH * SCREEN_HEIGHT * 2); pos += 2) {
        vidptr[pos] = ' ';
    }
}

/**
 * Move hardware cursor to x, y coords
 */
void move_hw_cursor(int x, int y) {
    // @STODO - Move hardware cursor to software cursor position
    unsigned short position = (y * 80) + x;
    cursorX = x;
    cursorY = y;
    // High byte
    write_port(0x3D4, 0x0F);
    write_port(0x3D5, (unsigned char) (position & 0xFF));
    
    // Low byte
    write_port(0x3D4, 0x0E);
    write_port(0x3D5, (unsigned char) ((position >> 8) & 0xFF));
}

void init_video() {
    vidptr = (unsigned char*) 0xB8000;
    cls();
}

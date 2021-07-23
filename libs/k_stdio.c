#include "k_stdio.h"
#include "keyboard.h"
#include "screen.h"
// printf()
// sprintf()
// vprintf()
// vsprintf()
// scanf()
// sscan()

char getchar(){
    while (1) {
        char cChar = keyboard_handler();
        if (cChar != 0) {
            return cChar;
        }
    }
}

char* gets(){
    char *line;

    for (int i = 0; i < 128; i++) {
        int charFound = 0;
        while (charFound == 0) {
            char cChar = keyboard_handler();
            if (cChar != 0) {
                line[i] = cChar;
                putch(cChar);
                charFound = 1;
            }
        }
        if (line[i] == '\n') {
            line[i] = '\0';
            return line;
        }
    } return line;
}

void putch(unsigned char c) {
    unsigned int location;

    // Backspace
    if (c == '\b') {
        if (cursorX != 0) cursorX--;
    }

    // Carriage return
    else if (c == '\r') {
        cursorX = 0;
    }

  // Newline
    else if (c == '\n') {
        cursorX = 0;
        cursorY++;
    }

    // Non-special characters
    else if (c >= ' ') {
        location = ((cursorY * SCREEN_WIDTH) + cursorX) * 2;
        vidptr[location] = c;
        vidptr[location + 1] = attr;
        cursorX++;
    }

  // Move cursor to next line if it's beyond the right edge of the screen
    if (cursorX >= SCREEN_WIDTH) {
        cursorX = 0;
        cursorY++;
    }

  // Scroll the screen up if necessary
    if (cursorY >= SCREEN_HEIGHT) {
        cursorY = SCREEN_HEIGHT - 1;
        scroll_up();
    }

    move_hw_cursor(cursorX, cursorY);
}

void puts(char str[]) {
    int i = 0;

    while(str[i] != '\0') {
        putch(str[i]);
        i++;
    }
}
// perror()

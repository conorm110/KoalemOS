#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

unsigned char *vidptr; // Video memory lives here

// Software cursor
int cursorX;
int cursorY;

char attr;

void cls();
void putch(unsigned char c);
void scroll_up();
void init_video();
void move_hw_cursor(int x, int y);


#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

unsigned char *vidptr; 

int cursorX;
int cursorY;

char attr;

void cls();
void scroll_up();
void init_video();
void move_hw_cursor(int x, int y);
void disable_cursor();
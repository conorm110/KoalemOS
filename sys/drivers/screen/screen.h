/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

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
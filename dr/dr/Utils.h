#pragma once

void sleepMs(int ms);
void hideCursor();
void moveCursorToTopLeft();

#ifndef _WIN32
int _kbhit();
int _getch();
#else

#include <conio.h>
#endif

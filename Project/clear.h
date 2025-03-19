#ifndef CLEAR_H
#define CLEAR_H

#include <iostream>
#include <ncurses.h>
#include <curses.h>

void cleen_enterwin(WINDOW *enterwin);
void cleen_startwin(WINDOW *startwin);
void move_enterwin(WINDOW *enterwin);
void my_clases();

#endif

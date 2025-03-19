#include "clear.h"
#include "game.h"

void cleen_enterwin(WINDOW * enterwin)
{
    for(int i = 2; i < 22; i++)
    {
        wprintw(enterwin, " ");
    }
}

void cleen_startwin(WINDOW *startwin)
    {
    for(int i = 2; i < 80; i++)
    {
        wprintw(startwin, " ");
    }
}

void move_enterwin(WINDOW *enterwin)
{
    wmove(enterwin, 1, 2);
    cleen_enterwin(enterwin);
    wmove(enterwin, 1, 2);
    wrefresh(enterwin);
}

void my_clases()
{
    Story library;
    Describe_game gameDescribtion(library);
    sleep(10);

    Describe_character Describtion(library);
    sleep(10);

    Describe_challange challangeDescribtion(library);
    sleep(5);

    Describe_management managementDescribtion(library);
    sleep(5);
}

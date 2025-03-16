#include "start.h"
#include <cstdlib>
#include <ncurses.h>

void start(bool &start_game_end)
{
    initscr();
    cbreak();
    WINDOW * menuwin = newwin(10, 90, 0, 0);
    box(menuwin, 0 , 0);
    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);
    std::string menu[2] = {"START", "EXIT"};
    int choise;
    int light = 0;
    while(true)
    {
        for(int i = 0; i < 2; i++)
        {
            if(i == light)
            {
                wattron(menuwin, A_REVERSE);
                mvwprintw(menuwin, i + 4, 40, "%s", menu[i].c_str());
                wattroff(menuwin, A_REVERSE);
            }
            else
            {
                mvwprintw(menuwin, i + 4, 40, "%s", menu[i].c_str());
            }
        }
        choise = wgetch(menuwin);
        switch (choise)
        {
            case KEY_UP:
                light--;
                if(light == -1)
                {
                    light = 0;
                }
                break;
            case KEY_DOWN:
                light++;
                if(light == 2)
                {
                    light = 1;
                }
                break;
                //case KEY_ENTER:
                //    break;
            default:
                break;
        }
        if(choise == 10 && light == 0)
        {
            start_game_end = true;
            break;
        } else if (choise == 10 && light == 1)
        {
            start_game_end = false;
            break;
        }

    }
    wmove(menuwin, 5, 1);
        for(int i = 2; i < 86; i++)
        {
            wprintw(menuwin, " ");
        }
        wmove(menuwin, 6, 1);
        for(int i = 2; i < 86; i++)
        {
            wprintw(menuwin, " ");
        }
//werase(menuwin);
    wclear(menuwin);
    wrefresh(menuwin);
        delwin(menuwin);
        endwin();

}

/*int main()
{
    initscr();
    cbreak();
    WINDOW * menuwin = newwin(10, 90, 0, 0);
    box(menuwin, 0 , 0);
    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);
    std::string menu[2] = {"START", "EXIT"};
    int choise;
    int light = 0;
    while(true)
    {
        for(int i = 0; i < 2; i++)
        {
            if(i == light)
            {
                wattron(menuwin, A_REVERSE);
                mvwprintw(menuwin, i + 4, 40, "%s", menu[i].c_str());
                wattroff(menuwin, A_REVERSE);
            }
            else
            {
                mvwprintw(menuwin, i + 4, 40, "%s", menu[i].c_str());
            }
        }
        choise = wgetch(menuwin);
        switch (choise)
        {
            case KEY_UP:
                light--;
                if(light == -1)
                {
                    light = 0;
                }
                break;
            case KEY_DOWN:
                light++;
                if(light == 2)
                {
                    light = 1;
                }
                break;
            //case KEY_ENTER:
            //    break;
            default:
                break;
            }
            if(choise == 10 && menu[0] == "START")
            {
                break;
            } else if (choise == 10 && menu[1] == "EXIT") {
                break;
            }
            clear();
    }
    return 0;
}*/

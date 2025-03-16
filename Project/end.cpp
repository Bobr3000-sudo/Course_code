#include "end.h"
#include <cstdlib>
#include <ncurses.h>

void End(std::string name)
{

    initscr();
    cbreak();
    clear();
    WINDOW * startwin = newwin(10, 90, 0, 0);
    box(startwin, 0 , 0);
    refresh();
    wrefresh(startwin);
    mvwprintw(startwin, 3, 30, "Thank you for playing ");
    wrefresh(startwin);
  //std::cout << "Thank you for playing ";
  std::ifstream in("Player_info.txt");
    if (in.is_open())
    {
        while (std::getline(in, name))
        {
            //mvwprintw(startwin, 1, 40, name);
            std::cout << name << std::endl;
        }
    }
    in.close();
    mvwprintw(startwin, 5, 30, "Creator: Kostiantyn Korchuhanov");
    wrefresh(startwin);
    //std::cout << "\n\nCreator: Kostiantyn Korchuhanov\n";
    sleep(5);
    std::ofstream file("example.txt");
    if (file.is_open())
    {
        file.close();
    }
}

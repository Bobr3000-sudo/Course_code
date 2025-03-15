#include "end.h"
#include <ncurses.h>

void End(std::string name)
{
    initscr();
    cbreak();
    WINDOW * startwin = newwin(10, 90, 0, 0);
    box(startwin, 0 , 0);
    refresh();
    wrefresh(startwin);
    mvwprintw(startwin, 0, 40, "Thank you for playing\n");
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
    mvwprintw(startwin, 0, 40, "\nCreator: Kostiantyn Korchuhanov");
    //std::cout << "\n\nCreator: Kostiantyn Korchuhanov\n";
    sleep(5);
    std::ofstream file("example.txt");
    if (file.is_open())
    {
        file.close();
    }
}

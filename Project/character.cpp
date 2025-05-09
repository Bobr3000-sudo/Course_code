#include "character.h"
#include <cstdlib>
#include <cwctype>
#include <ncurses.h>
#include <unistd.h>

bool empty_age(std::string const &age)
{
    if(age.empty())
    {
        return false;
    }
    for(char val : age)
    {
        if(!iswdigit(val))
        {
            return false;
        }
    }
    return true;
}

bool age_controller(int input_age, const Character &game_character)
    {
        initscr();
        cbreak();
        WINDOW * startwin = newwin(10, 90, 0, 0);
        box(startwin, 0 , 0);
        refresh();
        wrefresh(startwin);
    if(input_age >= 18)
    {
        mvwprintw(startwin, 3, 30, "Welcome to the game 'Paradigma'!");
        wrefresh(startwin);
        mvwprintw(startwin, 4, 18, "Your character was created, your character`s name is: %s", game_character.Get_name().c_str());
        wrefresh(startwin);
        sleep(3);
        return true;
    }
    else
    {
        if(input_age == 0)
        {
            mvwprintw(startwin, 4, 25, "Impossible 0_0");
            wrefresh(startwin);
            sleep(3);
            return false;
        }
        else
        {
            mvwprintw(startwin, 4, 25, "You are too young to play in this game");
            wrefresh(startwin);
            sleep(3);
            return false;
        }
    }
}

bool name_controller(std::string const &input_name)
{
    return !input_name.empty();
}

bool only_letters(std::string const &input_name)
{
    return std::all_of(input_name.begin(), input_name.end(), [] (char const &c)
    {
        return std::isalpha(c);
    });
}

void start_game(std::string start)
{
    initscr();
    cbreak();
    WINDOW * startwin = newwin(10, 90, 0, 0);
    box(startwin, 0 , 0);
    refresh();
    wrefresh(startwin);
    start = "Game will start now";
    mvwprintw(startwin, 3, 35, "%s", start.c_str());
    wrefresh(startwin);
}

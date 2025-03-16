#include "character.h"
#include <ncurses.h>
#include <unistd.h>

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
        //std::cout << "Welcome to the game 'Paradigma'!" << std::endl;
        //std::cout << "Your character was created, your character`s name is: " << game_character.Get_name() << std::endl;
        return true;
    }
    else
    {
        if(input_age == 0)
        {
            mvwprintw(startwin, 1, 1, "Impossible 0_0 %c", 18 - input_age);
            wrefresh(startwin);
            sleep(3);
            //std::cout << "Impossible 0_0, try again or enter after " << 18 - input_age << " years";
            return false;
        }
        else
        {
            mvwprintw(startwin, 1, 1, "You are too young to play in this game, try again after %c", 18 - input_age);
            wrefresh(startwin);
            sleep(3);
            //std::cout << "You are too young to play in this game, try again after " << 18 - input_age << " years ;) ";
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

    //std::cout << start;
}

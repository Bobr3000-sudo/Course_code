#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <unistd.h>
#include "ncurses.h"

class History{
public:
    std::string describe;
    std::string game;
    std::string challange;
    std::string management;
};

class Describe_game : History
{
public:
    Describe_game(History& library)
    {
        WINDOW * startwin = newwin(10, 90, 0, 0);
        box(startwin, 0 , 0);
        refresh();
        wrefresh(startwin);
        game = "In this game, you will take on the role of a brave hero who must use his skills and wits to overcome many challenges. Each dungeon is full of mysteries that require logical thinking and a strategic approach. Your hero has unique abilities that will help you solve puzzles and overcome obstacles. Lets start ;)";
        mvwprintw(startwin, 1, 0, "%s", game.c_str());
        wrefresh(startwin);
        //std::cout << game;
        //std::cout << std::endl;
    }
};

class Describe_character : History
{
public:
    Describe_character(History& library)
    {
        WINDOW * startwin = newwin(10, 90, 0, 0);
        box(startwin, 0 , 0);
        refresh();
        wrefresh(startwin);
        describe = "You are a young explorer full of enthusiasm and a thirst for adventure. You are about twenty-five years old and have a sturdy physique that allows you to handle physical challenges with ease. You have short dark hair and penetrating brown eyes that are always looking for new horizons and mysteries";
        mvwprintw(startwin, 1, 0, "%s", describe.c_str());
        wrefresh(startwin);
        //std::cout << describe;
        //std::cout << std::endl;
    }
};
class Describe_challange : History
{
public:
    Describe_challange(History& library)
    {
        WINDOW * startwin = newwin(10, 90, 0, 0);
        box(startwin, 0 , 0);
        refresh();
        wrefresh(startwin);
        challange = "You need to solve all the riddles (3) to escape from the dungeon";
        mvwprintw(startwin, 1, 0, "%s", challange.c_str());
        wrefresh(startwin);
        //std::cout << challange;
        //std::cout << std::endl;
    }
};

class Describe_management : History {
public:
    Describe_management(History& library)
    {
        WINDOW * startwin = newwin(10, 90, 0, 0);
        box(startwin, 0 , 0);
        refresh();
        wrefresh(startwin);
        management = "To get around, use the keys such as: left, right, straight, down and ENTER to solve questions.\n"
        "Write the answer in one word with a small letter";
        mvwprintw(startwin, 1, 0, "%s", management.c_str());
        wrefresh(startwin);
        //std::cout << management;
        //std::cout << std::endl;
    }
};

#endif

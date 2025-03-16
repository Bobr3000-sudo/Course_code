#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "ncurses.h"

class History{
public:
    std::string describe;
    std::string describe_1;
    std::string describe_2;
    std::string describe_3;
    std::string describe_4;
    std::string describe_5;
    std::string game;
    std::string game_1;
    std::string game_2;
    std::string game_3;
    std::string game_4;
    std::string game_5;
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
        game =   "In  this  game,  you  will  take on  the role  of a  brave hero";
        game_1 = "who  must use his skills and wits  to overcome many challenges.";
        game_2 = "Each dungeon is full of mysteries that require logical thinking";
        game_3 = "and  a strategic  approach.  Your  hero  has  unique  abilities";
        game_4 = "that  will  help  you  solve puzzles and overcome obstacles.";
        game_5 = "Lets start ;)";

        mvwprintw(startwin, 2, 13, "%s", game.c_str());
        wrefresh(startwin);
        mvwprintw(startwin, 3, 13, "%s", game_1.c_str());
        wrefresh(startwin);
        mvwprintw(startwin, 4, 13, "%s", game_2.c_str());
        wrefresh(startwin);
        mvwprintw(startwin, 5, 13, "%s", game_3.c_str());
        wrefresh(startwin);
        mvwprintw(startwin, 6, 13, "%s", game_4.c_str());
        wrefresh(startwin);
        mvwprintw(startwin, 7, 13, "%s", game_5.c_str());
        wrefresh(startwin);
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
        describe = "You are a young explorer full of enthusiasm a thirst";
        describe_1 = "for adventure. You are about twenty-five years old";
        describe_2 = "have a sturdy physique that allows you  to  handle";
        describe_3 = "challenges with ease. You have short dark hair and";
        describe_4 = "brown eyes that are always looking for new horizons";
        describe_5 = "and mysteries";
        mvwprintw(startwin, 2, 15, "%s", describe.c_str());
        wrefresh(startwin);
        mvwprintw(startwin, 3, 15, "%s", describe_1.c_str());
        wrefresh(startwin);
        mvwprintw(startwin, 4, 15, "%s", describe_2.c_str());
        wrefresh(startwin);
        mvwprintw(startwin, 5, 15, "%s", describe_3.c_str());
        wrefresh(startwin);
        mvwprintw(startwin, 6, 15, "%s", describe_4.c_str());
        wrefresh(startwin);
        mvwprintw(startwin, 7, 15, "%s", describe_5.c_str());
        wrefresh(startwin);
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
        challange = "You need to solve all the riddles (4) to escape from the dungeon";
        mvwprintw(startwin, 4, 9, "%s", challange.c_str());
        wrefresh(startwin);
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
        management = "Navigate: left, right, up, down. Write the answer in one word with a small letter";
        mvwprintw(startwin, 4, 4, "%s", management.c_str());
        wrefresh(startwin);
    }
};

#endif

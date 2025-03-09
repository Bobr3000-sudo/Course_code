#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <ncurses.h>
#include <curses.h>

class tricks{
private:
    std::vector <std::string> Quastions;
public:
    tricks()
    {
        Quastions = {
            {"What is the most common digit between 1 and 1000 inclusive ?"},
            {"Which month has 28 days? "},
            {"6 people built a barn in 9 hours. How long would it take 12 builders to build the same barn? "}};
    }
    const std::vector <std::string>& get_quastions() const{
        return Quastions;
    }
};

class answears_tricks
{
private:
    std::vector <std::string> Answears;
public:
    answears_tricks()
    {
        Answears = {{"one"}, {"all"}, {"zero"}};
    }
    const std::vector<std::string>& get_answears() const{
        return Answears;
    }
};

class motivation
{
private:
    std::vector<std::string> Wrong;
public:
    motivation()
    {
        Wrong = {
            {"How great it is that you can try endlessly here!"},
            {"How nice it is that we have an unlimited number of chances!"},
            {"There are no miracles here, just keep experimenting!"},
            {"How wonderful it is that you can attempt as many times as you want!"},
            {"There are no hidden powers here, just try again!"},
            {"How cool it is that we have the opportunity to repeat our attempts!"},
            {"There are no tricks here, just keep taking action!"},
            {"How good it is that you can limitlessly try!"},
            {"There are no secrets here, just keep searching for a solution!"}};
    }
    const std::vector <std::string>& get_motivation() const{
        return Wrong;
    }
};

class motivation_strong
{
private:
    std::vector <std::string> Wrong_strong;
public:
    motivation_strong()
    {
        Wrong_strong = {
        {""},
        {"Are you AI?"},
        {"The probability of guessing a random 2-letter word is approximately 0.00148 or 0.148%"},
        {"The probability of guessing a random 3-letter word is approximately 0.0000568 or 0.00568%"},
        {"The probability of guessing a random 4-letter word is approximately 0.00000219 or 0.000219%"},
        {"The probability of guessing a random 5-letter word is approximately 0.0000000842 or 0.00000842%"}};
    }
    const std::vector <std::string>& get_motivation_strong() const
    {
        return Wrong_strong;
    }
};

void run_map(char *map, int &character_x, int &character_y, bool& end_game);

#endif

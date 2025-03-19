#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>
#include <algorithm>
#include "ncurses.h"

class Character{
public:
    Character(std::string character_name)
    {
        name = character_name;
    }
    std::string Get_name() const
    {
        return name;
    }
private:
    std::string name;
};

class Character_age
{
public:
    Character_age(int character_age)
    {
        age = character_age;
    }
    int Get_age() const
    {
        return age;
    }
private:
    int age;
};

bool empty_age(std::string const &age);
bool age_controller(int input_age, const Character &game_character);
bool name_controller(std::string const &input_name);
bool only_letters(std::string const &input_name);
void start_game(std::string start);

#endif

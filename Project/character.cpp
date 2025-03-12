#include "character.h"

bool age_controller(int input_age, const Character &game_character)
    {
    if(input_age >= 18)
    {
        std::cout << "Welcome to the game 'Paradigma'!" << std::endl;
        std::cout << "Your character was created, your character`s name is: " << game_character.Get_name() << std::endl;
        return true;
    }
    else
    {
        if(input_age == 0)
        {
            std::cout << "Impossible 0_0, try again or enter after" << 18 - input_age << " years";
            return false;
        }
        else
        {
            std::cout << "You are too young to play in this game, try again after " << 18 - input_age << " years ;) ";
            return false;
        }
    }
}

void start_game(std::string start)
{
    start = "Game will start now";
    std::cout << start;
}

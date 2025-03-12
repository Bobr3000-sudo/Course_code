#include "character.h"
#include "game.h"
#include "map.h"
#include "end.h"
#include <cctype>

int main() {
    system("clear");
    bool end_game = true;
    const int WIDTH = 15;
    const int HEIGHT = 11;
    int character_x;
    int character_y;

    char map[] = "###############\n"
    "#           ! ~\n"
    "#   ###########\n"
    "#   #          \n"
    "#   #######    \n"
    "#   !     #    \n"
    "#######   #    \n"
    "      #   #    \n"
    "#######   #####\n"
    "# !       !   #\n"
    "###############\n";
    char character = '@';

    std::string input_name;
    std::cout << "Enter character`s name: " << std::endl;
    std::getline(std::cin, input_name);
    int check;
    while(check != input_name.size())
    {
        check = 0;
        for(char val :input_name)
        {
            if(isalpha(val))
            {
                check++;
            }
        }
        if(check == input_name.size())
        {
            break;
        }
        else
        {
            std::cout << "Invalid name " << std::endl;
            std::cout << "Try again: ";
            return 0;
        }
    }

    std::ofstream out;
    out.open("Player_info.txt");
    if (out.is_open())
    {
        out << input_name << std::endl;
    }
    out.close();

    Character game_character(input_name);
    int input_age;
    std::cout << "Enter your age: " << std::endl;
    std::cin >> input_age;
    Character_age game_character_age(input_age);

    if (!age_controller(input_age, game_character))
    {
        return 0;
    }

    std::cout << std::endl;
    std::string start;
    start_game(start);
    system("clear");
    std::cout << std::endl;

    History library;
    Describe_game gameDescribtion(library);
    sleep(12);
    system("clear");

    Describe_character Describtion(library);
    sleep(11);
    system("clear");

    Describe_challange challangeDescribtion(library);
    sleep(6);
    system("clear");

    Describe_management managementDescribtion(library);
    sleep(10);
    system("clear");

    run_map(map, character_x, character_y, end_game);

    End(input_name);

    clock_t before = clock();
    int count = 0;
    for (int i = 0; i < 100000 ; i++)
    {
        count = count + i;
    }
    clock_t programm_running = clock() - before;
    std::cout << "Programm run time: " << (float)programm_running/CLOCKS_PER_SEC << " seconds";
    endwin();
    return 0;
}

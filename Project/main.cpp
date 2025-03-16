#include "character.h"
#include "game.h"
#include "map.h"
#include "end.h"
#include "start.h"

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ncurses.h>
#include <string>

int main()
{
    bool start_game_end = true;
    start(start_game_end);
    if(start_game_end)
    {
        initscr();
        cbreak();
        WINDOW * startwin = newwin(10, 90, 0, 0);
        box(startwin, 0, 0);
        refresh();
        wrefresh(startwin);

        WINDOW * enterwin = newwin(3, 25, 5, 35);
        box(enterwin, 0, 0);
        refresh();
        wrefresh(enterwin);

        bool end_game = true;
        const int WIDTH = 15;
        const int HEIGHT = 11;
        int character_x = 12;
        int character_y = 9;

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

        mvwprintw(startwin, 3, 27, "Enter character`s name (use only letters): ");
        wrefresh(startwin);
        char input_name[20];
        bool check;
        do
        {
            wmove(enterwin, 1, 2);
            for(int i = 2; i < 22; i++)
            {
                wprintw(enterwin, " ");
            }
            wmove(enterwin, 1, 2);
            wgetnstr(enterwin, input_name, sizeof(input_name) - 1);
            wrefresh(enterwin);
            check = only_letters(input_name);
        }
        while(!name_controller(input_name) || !check);

        Character game_character(input_name);
        std::ofstream out;
        out.open("Player_info.txt");
        if (out.is_open())
        {
            out << input_name << std::endl;
        }
        out.close();

        int input_age;
        char input_age_converter[3];
        wmove(startwin, 3, 1);
        for(int i = 2; i < 80; i++)
        {
            wprintw(startwin, " ");
        }
        while(true)
        {
            wrefresh(enterwin);
            wrefresh(startwin);
            mvwprintw(startwin, 3, 39, "Enter your age: ");
            wrefresh(startwin);
            wmove(enterwin, 1, 2);
            for(int i = 2; i < 22; i++)
            {
                wprintw(enterwin, " ");
            }
            wmove(enterwin, 1, 2);
            wgetnstr(enterwin, input_age_converter, sizeof(input_age_converter) - 1);
            wrefresh(enterwin);
            if(empty_age(input_age_converter))
            {
                input_age = std::stoi(input_age_converter);
                break;
            }
            else
            {
                wrefresh(enterwin);
                wrefresh(startwin);
                mvwprintw(startwin, 3, 39, "Enter your age: ");
                wrefresh(startwin);
                wmove(enterwin, 1, 2);
                for(int i = 2; i < 22; i++)
                {
                    wprintw(enterwin, " ");
                }
                wmove(enterwin, 1, 2);
                wgetnstr(enterwin, input_age_converter, sizeof(input_age_converter) - 1);
                wrefresh(enterwin);
            }
        }
        Character_age game_character_age(input_age);
        if (!age_controller(input_age, game_character))
        {
            return 0;
        }
        std::string start;
        start_game(start);

        History library;
        Describe_game gameDescribtion(library);
        sleep(10);

        Describe_character Describtion(library);
        sleep(10);

        Describe_challange challangeDescribtion(library);
        sleep(5);

        Describe_management managementDescribtion(library);
        sleep(5);
        endwin();
        run_map(map, character_x, character_y, end_game);

        End(input_name);
    }
    else
    {
        mvprintw(1, 1, "OK...");
    }
    refresh();
    endwin();
    return 0;
}

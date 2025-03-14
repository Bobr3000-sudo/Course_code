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
            {"6 people built a barn in 9 hours. How long would it take 12 builders to build the same barn? "},
            {"All five-digit numbers are written on the board, each digit of which is either equal to both adjacent numbers, or differs from the neighboring ones by exactly one - from one to a lesser one, and from the other to a higher one. How many numbers written on the board contain the number 5 in their notation?"}
        };
    }
    std::vector <std::string>& get_quastions()
    {
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
        Answears = {{"one"}, {"all"}, {"zero"}, {"eleven"}};
    }
    std::vector<std::string>& get_answears()
    {
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

int main()
{
    tricks TRICKS;
    answears_tricks ANSWEARS_TRICKS;
    motivation MOTIVATION;
    motivation_strong MOTIVATION_STRONG;
    bool end_game = true;
    const int WIDTH = 15;
    const int HEIGHT = 11;
    int character_x = 12;
    int character_y = 9;
    int score = 0;

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
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    int input_key;
    while (end_game)
    {
        for(int i = 0; i < HEIGHT; i++)
        {
            mvprintw(i, 0, "%s", map + (WIDTH + 1) * i);
        }
        mvprintw(character_y, character_x, "%c", character);
        int check = character_y * (WIDTH + 1) + character_x;
        refresh();
        input_key = getch();
        if(input_key == KEY_LEFT)
        {
            if(map[check - 1] == '#')
                continue;
            else
                character_x--;
        }
        if(input_key == KEY_RIGHT)
        {
            if(map[check + 1] == '#')
                continue;
            else
                character_x++;
        }
        if(input_key == KEY_UP)
        {
            if(map[check - 16] == '#')
                continue;
            else
                character_y--;
        }
        if(input_key == KEY_DOWN)
        {
            if(map[check + 16] == '#')
                continue;
            else
                character_y++;
        }
        if (map[check] == '!')
        {
            clear();
            mvprintw(1, 1, "You found a question! Press 'ENTER' key to see it.");
            mvprintw(2, 1, "Press 'BACKSPACE' key to go out.");
            refresh();
            int press_key;
            press_key = getch();
            if(press_key == '\n')
            {
                clear();
                map[check] = ' ';
                std::string iteration = TRICKS.get_quastions()[rand() % TRICKS.get_quastions().size()];
                mvprintw(1, 0, "%s", iteration.c_str());
                auto it = std::find(TRICKS.get_quastions().begin(), TRICKS.get_quastions().end(), iteration);
                int distance = std::distance(TRICKS.get_quastions().begin(), it);
                char input[100];
                int try_answear = 0;
                while (input != ANSWEARS_TRICKS.get_answears()[distance])
                {
                    getnstr(input, sizeof(input) - 1);
                    if(try_answear < 5)
                    {
                        clear();
                        mvprintw(1, 0, "%s", iteration.c_str());
                        mvprintw(4, 0, "%s", MOTIVATION.get_motivation()[rand() % MOTIVATION.get_motivation().size()].c_str());
                        printw("\nAgain: ");
                    }
                    else
                    {
                        clear();
                        mvprintw(1, 0, "%s", iteration.c_str());
                        mvprintw(4, 0, "%s", MOTIVATION_STRONG.get_motivation_strong()[rand() % MOTIVATION_STRONG.get_motivation_strong().size()].c_str());
                        printw("\nAgain: ");
                    }
                    try_answear++;
                }
                ANSWEARS_TRICKS.get_answears().erase(ANSWEARS_TRICKS.get_answears().begin() + distance);
                TRICKS.get_quastions().erase(TRICKS.get_quastions().begin() + distance);
                score++;
            }
            else if(press_key == KEY_BACKSPACE)
            {
                continue;
            }
        }
        if(score == 4)
        {
            end_game = false;
        }
    }
    endwin();
    return 0;
}

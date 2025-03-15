#include "map.h"

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

void run_map(char *map, int &character_x, int &character_y, bool &end_game)
{
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
            mvprintw(1, 0, "You found a question! Press 'ENTER' key to see it.");
            mvprintw(2, 0, "Press 'BACKSPACE' key to go out.");
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
        if(score == 4 && map[check] == '~')
        {
            end_game = false;
        }
    }
    endwin();
}

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
    run_map(map, character_x, character_y, end_game);
    return 0;
}

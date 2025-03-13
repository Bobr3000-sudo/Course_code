#include "map.h"

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

void run_map(char *map, int &character_x, int &character_y, bool& end_game)
{
    tricks TRICKS;
    answears_tricks ANSWEARS_TRICKS;
    motivation MOTIVATION;
    motivation_strong MOTIVATION_STRONG;
    character_x = 12;
    character_y = 9;
    int score = 0;
    std::string x;
    int charr;
    initscr();
    cbreak();
    start_color();
    keypad(stdscr, TRUE);

    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    attron(COLOR_PAIR(1));
    while(end_game)
    {
        for(int i = 0; i < HEIGHT; i++)
        {
            mvprintw(i, 0,"%s", map + i * (WIDTH + 1));
        }
        mvprintw(character_y, character_x, "%c", character);
        charr = getch();
        int check = character_y * (WIDTH + 1) + character_x;
        if (charr == KEY_LEFT)
        {
            if(map[check - 1] == '#')
            {
                character_x = character_x;
                character_y = character_y;
            }
            else
            {
                character_x = character_x - 1;
                character_y = character_y;
            }
        }
        if(charr == KEY_RIGHT)
        {
            if(map[check + 1] == '#' || (map[check + 1] == '~' && score < 4))
            {
                character_x = character_x;
                character_y = character_y;
            }
            else
            {
                character_x = character_x + 1;
                character_y = character_y;
            }
        }
        if (charr == KEY_UP)
        {
            if(map[check - 16] == '#')
            {
                character_x = character_x;
                character_y = character_y;
            }
            else
            {
                character_x = character_x;
                character_y = character_y - 1;
            }
        }
        if(charr == KEY_DOWN)
        {
            if(map[check + 16] == '#')
            {
                character_x = character_x;
                character_y = character_y;
            }
            else
            {
                character_x = character_x;
                character_y = character_y + 1;
            }
        }
        while(map[check] == '!')
        {
            character_x = character_x;
            character_y = character_y;
            clear();
            mvprintw(1, 1, "You found a question! Press 'ENTER' key to see it.");
            mvprintw(2, 1, "Press 'BACKSPACE' key to go out.");
            refresh();
            int press_key;
            press_key = getch();

            if (press_key == KEY_ENTER || press_key == '\n')
            {
                clear();
                map[check] = ' ';
                std::string iteration = TRICKS.get_quastions()[rand() % TRICKS.get_quastions().size()];
                auto it = std::find(TRICKS.get_quastions().begin(), TRICKS.get_quastions().end(), iteration);
                int distance = std::distance(TRICKS.get_quastions().begin(), it);
                mvprintw(0, 0, "%s", iteration.c_str());

                char input[1000];
                int count = 0;
                while (input != ANSWEARS_TRICKS.get_answears()[distance])
                {
                    getnstr(input, sizeof(input) - 1);
                    //printw("\nYour input: %s", input);
                    if(input != ANSWEARS_TRICKS.get_answears()[distance])
                    {
                        printw("\nAgain: ");
                    }
                    if(count < 10)
                    {
                        clear();
                        mvprintw(1, 0, "%s", iteration.c_str());
                        mvprintw(2, 0, "%s", MOTIVATION.get_motivation()[rand() % MOTIVATION.get_motivation().size()].c_str());
                        printw("\nAgain: ");
                    }
                    else if(count >= 10)
                    {
                        clear();
                        mvprintw(1, 0, "%s", iteration.c_str());
                        mvprintw(2, 0, "%s", MOTIVATION_STRONG.get_motivation_strong()[rand() % MOTIVATION_STRONG.get_motivation_strong().size()].c_str());
                        printw("\nAgain: ");
                    }
                    count++;
                }
                if(input == ANSWEARS_TRICKS.get_answears()[distance])
                {
                    score = score + 1;
                    break;
                }
                if(score == 4)
                {
                    break;
                }
                ANSWEARS_TRICKS.get_answears().erase(ANSWEARS_TRICKS.get_answears().begin() + distance);
                TRICKS.get_quastions().erase(TRICKS.get_quastions().begin() + distance);
                getch();
            }
            else if (press_key == KEY_BACKSPACE)
            {
                break;
            }
        }

        refresh();
        if(character_x == 14 && character_y == 1 && score == 3)
        {
            end_game = false;
        }
    }
    attroff(COLOR_PAIR(1));
    endwin();
}

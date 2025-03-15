#include "map.h"

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

int main()
//void run_map(char *map, int &character_x, int &character_y, bool &end_game)
{
    tricks TRICKS;
    answears_tricks ANSWEARS_TRICKS;
    motivation MOTIVATION;
    motivation_strong MOTIVATION_STRONG;

        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        int input_key;

        int start_x = 0;
        int start_y = 0;
        int height = HEIGHT + 2;
        int weight = WIDTH + 2;
        WINDOW * win = newwin(height, weight, start_x, start_y);
        refresh();
        box(win, 0, 0);

        int start_text_y = WIDTH + 2;
        int start_text_x = 0;
        WINDOW * win_text = newwin(height, weight + 70, start_text_x, start_text_y);
        refresh();
        box(win_text, 0, 0);

        while (end_game)
        {
            wmove(win_text, 1, 1);
            wclrtoeol(win_text);
            wmove(win_text, 2, 1);
            wclrtoeol(win_text);
            wmove(win_text, 3, 1);
            wclrtoeol(win_text);
            wmove(win_text, 4, 1);
            wclrtoeol(win_text);
            wrefresh(win_text);
            for(int i = 0; i < HEIGHT; i++)
            {
                mvwprintw(win, i + 1, 1, "%.*s", weight - 2, map + (WIDTH + 1) * i);

            }
            wrefresh(win);
            mvwprintw(win, character_y + 1, character_x + 1, "%c", character);
            wrefresh(win);
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
                mvwprintw(win_text, 1, 1, "You found a question! Press 'ENTER' key to see it.");
                wrefresh(win_text);
                mvwprintw(win_text, 2, 1, "Press 'BACKSPACE' key to go out.");
                wrefresh(win_text);
                int press_key;
                press_key = getch();
                if (press_key == '\n')
                {
                    map[check] = ' ';
                    std::string iteration = TRICKS.get_quastions()[rand() % TRICKS.get_quastions().size()];
                    wmove(win_text, 1, 1);
                    wclrtoeol(win_text);
                    wmove(win_text, 2, 1);
                    wclrtoeol(win_text);
                    mvwprintw(win_text, 1, 1, "%s", iteration.c_str());
                    wrefresh(win_text);
                    auto it = std::find(TRICKS.get_quastions().begin(), TRICKS.get_quastions().end(), iteration);
                    int distance = std::distance(TRICKS.get_quastions().begin(), it);
                    char input[100];
                    int try_answear = 0;
                    int x = 0;
                    while (input != ANSWEARS_TRICKS.get_answears()[distance])
                    {
                        if(x == 0)
                        {
                            mvwprintw(win_text, 4, 1, "Your answear: ");
                        }
                        x++;
                        memset(input, 0, sizeof(input));
                        wmove(win_text, 5, 1);
                        wclrtoeol(win_text);
                        wrefresh(win_text);
                        wgetnstr(win_text, input, sizeof(input) - 1);
                        wmove(win_text, 5, 1);
                        wclrtoeol(win_text);
                        wmove(win_text, 4, 1);
                        wclrtoeol(win_text);
                        wrefresh(win_text);
                        if(input == ANSWEARS_TRICKS.get_answears()[distance])
                        {
                            break;
                        }
                        else
                        {
                          mvwprintw(win_text, 1, 1, "%s", iteration.c_str());
                            wrefresh(win_text);
                            if(try_answear < 5)
                            {
                                wmove(win_text, 3, 1);
                                wclrtoeol(win_text);
                                mvwprintw(win_text, 3, 1, "%s", MOTIVATION.get_motivation()[rand() % MOTIVATION.get_motivation().size()].c_str());
                                wrefresh(win_text);
                            }
                            else
                            {
                                wmove(win_text, 3, 1);
                                wclrtoeol(win_text);
                                mvwprintw(win_text, 3, 1, "%s", MOTIVATION_STRONG.get_motivation_strong()[rand() % MOTIVATION_STRONG.get_motivation_strong().size()].c_str());
                                wrefresh(win_text);

                            }
                            wmove(win_text, 5, 1);
                            wclrtoeol(win_text);
                            mvwprintw(win_text, 4, 1, "Again: ");
                            wrefresh(win_text);
                            try_answear++;
                        }
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

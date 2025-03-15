#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <ctime>
#include <ncurses.h>
#include <curses.h>
#include <algorithm>


int main()
{
    class tricks{
    private:
        std::vector <std::string> Quastions;
    public:
        tricks()
        {
            Quastions = {
                {"What is the most common digit between 1 and 1000 inclusive ?"},
                {"Which month has 28 days? "},
                {"If 6 people build a barn in 9 hours, how long would it take 12 people? "},
                {"Husband, wife, brother, sister, and brother-in-law. How many people?"}
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
            Answears = {{"one"}, {"all"}, {"zero"}, {"three"}};
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
                {"The probability of guessing a random 2-letter word is 0.00148 or 0.148%"},
                {"The probability of guessing a random 3-letter word is 0.0000568 or 0.00568%"},
                {"The probability of guessing a random 4-letter word is 0.00000219 or 0.000219%"},
                {"The probability of guessing a random 5-letter word is 0.0000000842 or 0.00000842%"}};
        }
        const std::vector <std::string>& get_motivation_strong() const
        {
            return Wrong_strong;
        }
    };

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
    return 0;
}

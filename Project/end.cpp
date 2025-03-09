#include "end.h"

void End(std::string name)
{
  std::cout << "Thank you for playing ";
  std::ifstream in("Player_info.txt");
    if (in.is_open())
    {
        while (std::getline(in, name))
        {
            std::cout << name << std::endl;
        }
    }
    in.close();
    std::cout << "\n\nCreator: Kostiantyn Korchuhanov\n";
    sleep(5);
    std::ofstream file("example.txt");
    if (file.is_open())
    {
        file.close();
    }
}

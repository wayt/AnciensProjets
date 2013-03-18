/*
** main.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 10:07:35 2013 maxime ginters
** Last update Mon Jan 14 10:07:35 2013 maxime ginters
*/

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return 1;
    }

    std::string line;
    std::ifstream file;
    for (int i = 1; i < argc; ++i)
    {
        file.open(argv[i]);
        if (file.is_open())
        {
            char c;
            while (file.get(c))
            {
                std::cout << c;
            }
            file.close();
        }
        else
            std::cerr << "my_cat: " << argv[1] << ": No such file or directory" << std::endl;
    }
    return 0;
}


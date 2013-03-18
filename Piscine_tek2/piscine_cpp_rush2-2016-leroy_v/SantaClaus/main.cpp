/*
** main.cpp for SantaClaus in /home/leroy_v/Epitech/piscine2013/Rush2/piscine_cpp_rush2-2016-leroy_v/SantaClaus
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sun Jan 20 02:52:54 2013 vincent leroy
** Last update Sun Jan 20 02:54:51 2013 vincent leroy
*/

#include "SantaClaus.h"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "No input file" << std::endl;
        return 1;
    }

    SantaClaus santa;

    for (int i = 1; i < ac; ++i) {
        santa.checkFile(av[i]);
    }

    return 0;
}

/*
** main_ex00.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 10:20:04 2013 maxime ginters
** Last update Thu Jan 24 14:23:28 2013 maxime ginters
*/

#include "Parser.h"

int main()
{
    Parser p;
    p.feed("((523 +5)*(4*77))-(((4564/4564)*(45646+423))+(48797-7879))");
    std::cout << p.result() << std::endl;
    return 0;
}

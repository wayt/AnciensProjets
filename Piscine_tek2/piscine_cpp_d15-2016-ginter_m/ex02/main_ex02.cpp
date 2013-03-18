/*
** main.cpp for ex02 in /home/leroy_v/Epitech/projet_tek2/piscine/Jour_15/ex02
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Wed Jan 23 10:09:39 2013 vincent leroy
** Last update Thu Jan 24 07:42:10 2013 maxime ginters
*/

#include <iostream>
#include <string>
#include "ex02.hpp"

int main()
{
    int tab[2] = {3, 0};
    int minimum = templateMin(tab, 2);
    std::cout << "templateMin(tab, 2) = " << minimum << std::endl;
    minimum = nonTemplateMin(tab, 2);
    std::cout << "nonTemplateMin(tab, 2) = " << minimum << std::endl;

    return 0;
}

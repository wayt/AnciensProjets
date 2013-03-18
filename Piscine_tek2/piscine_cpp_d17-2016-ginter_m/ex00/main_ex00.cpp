/*
** main_ex00.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d17-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 25 09:49:22 2013 maxime ginters
** Last update Fri Jan 25 09:54:31 2013 maxime ginters
*/

#include <list>
#include <iostream>
#include "find.hpp"

int main()
{
    std::list<int> list;
    list.push_back(5);
    list.push_back(2);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(2);
    list.push_back(3);
    list.push_back(2);
    list.push_back(6);
    std::list<int>::iterator itr = do_find(list, 10);
    while (itr != list.end())
    {
        std::cout << *itr << std::endl;
        ++itr;
    }
    return 0;
}

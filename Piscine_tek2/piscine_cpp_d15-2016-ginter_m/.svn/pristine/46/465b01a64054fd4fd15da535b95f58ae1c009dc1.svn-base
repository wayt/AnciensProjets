/*
** ex03.hpp for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d15-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 23 11:18:49 2013 maxime ginters
** Last update Wed Jan 23 11:22:21 2013 maxime ginters
*/

#ifndef EX03_H_
# define EX03_H_

#include <iostream>

template<class T>
void print(T const& elem)
{
    std::cout << elem << std::endl;
}

template<class T>
void foreach(T const* t, void (*func)(const T& elem), size_t size)
{
    for (size_t i = 0; i < size; ++i)
        (func)(t[i]);
}

#endif /* !EX03_H_ */

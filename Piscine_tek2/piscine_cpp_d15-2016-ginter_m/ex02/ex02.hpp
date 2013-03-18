/*
** ex02.hpp for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d15-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 23 10:34:31 2013 maxime ginters
** Last update Thu Jan 24 09:08:33 2013 maxime ginters
*/

#ifndef EX02_H_
# define EX02_H_

#include <iostream>

template<class T>
T const& min(T const& a, T const& b)
{
    std::cout << "template min" << std::endl;
    if (a <= b)
        return a;
    return b;
}

template<>
int& min<int>(int& a, int& b)
{
    std::cout << "non-template min" << std::endl;
    if (a <= b)
        return a;
    return b;
}

template<class T>
T& templateMin(T* array, int size)
{
    T& mi = array[0];
    for (int i = 1; i < size; ++i)
        mi = min<T>(mi, array[i]);
    return mi;
}

int& nonTemplateMin(int *array, int size)
{
    int& mi = array[0];
    for (int i = 1; i < size; ++i)
        mi = min<int>(mi, array[i]);
    return mi;
}

#endif /* !EX02_H_ */

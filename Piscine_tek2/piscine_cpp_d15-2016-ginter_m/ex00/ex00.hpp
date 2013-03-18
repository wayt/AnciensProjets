/*
** ex00.hpp for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d15-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 23 09:29:12 2013 maxime ginters
** Last update Wed Jan 23 09:35:27 2013 maxime ginters
*/

#ifndef EX00_H_
# define EX00_H_

template<class T>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template<class T>
T min(T& a, T& b)
{
    if (a >= b)
        return b;
    return a;
}

template<class T>
T max(T& a, T& b)
{
    if (b >= a)
        return b;
    return a;
}

template<class T>
T add(T& a, T& b)
{
    return a + b;
}

#endif /* !EX00_H_ */

/*
** tab_to_2dtab.c for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02m-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 10:40:00 2013 maxime ginters
** Last update Thu Jan 10 10:53:41 2013 maxime ginters
*/

#include <stdlib.h>

void tab_to_2dtab(int* tab, int length, int width, int*** res)
{
    if ((*res = calloc(length, sizeof(int*))) == 0)
        return;

    int y;
    int x;
    for (y = 0; y < length; ++y)
    {
        if (((*res)[y] = calloc(width, sizeof(int))) == 0)
            return;
        for (x = 0; x < width; ++x)
            (*res)[y][x] = tab[y * width + x];
    }
}

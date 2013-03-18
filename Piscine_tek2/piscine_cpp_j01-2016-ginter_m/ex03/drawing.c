/*
** drawing.c for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 16:46:24 2013 maxime ginters
** Last update Wed Jan 09 17:07:34 2013 maxime ginters
*/
#include <string.h>
#include "drawing.h"

void draw_square(uint32_t** img, t_point* orig, size_t size, uint32_t color)
{
    for (size_t y = orig->y; y < orig->y + size; ++y)
        for (size_t x = orig->x; x < orig->x + size; ++x)
            img[y][x] = color;
}

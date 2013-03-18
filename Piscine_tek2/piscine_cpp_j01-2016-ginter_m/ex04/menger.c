/*
** menger.c for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 18:44:52 2013 maxime ginters
** Last update Wed Jan 09 18:46:59 2013 maxime ginters
*/

#include <stdint.h>
#include <stdlib.h>

#include "drawing.h"
#include "bitmap.h"

uint32_t get_color(uint32_t level)
{
    uint32_t color = 0;

    for (int16_t i = 2; i >= 0; --i)
        color |= (255 / level) << (i * 8);
    return color;
}

void menger(size_t size, uint32_t level, t_point* p, uint32_t** img)
{
    uint32_t s = (size / 3);
    uint32_t jump = size > 3 ? s : 1;
    t_point pts;
    pts.y = s + p->y;
    pts.x = s + p->x;
    draw_square(img, &pts, s, get_color(level));

    if (--level > 0)
        for (size_t s_row = 0; s_row < size; s_row += jump)
            for (size_t s_col = 0; s_col < size; s_col += jump)
            {
                if (s_row == jump && s_col == jump)
                    continue;
                t_point pt;
                pt.x = s_col + p->x;
                pt.y = s_row + p->y;
                menger(jump, level, &pt, img);
            }
}


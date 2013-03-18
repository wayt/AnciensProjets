/*
** menger.c for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 10:34:44 2013 maxime ginters
** Last update Wed Jan 09 18:18:52 2013 maxime ginters
*/

#include <stdio.h>

int menger(int size, int level, int col, int row)
{
    int s = (size / 3);
    int jump = size > 3 ? s : 1;

    int s_row;
    int s_col;
    printf("%03d %03d %03d\n", s, s + row, s + col);

    if (--level > 0)
        for (s_row = 0; s_row < size; s_row += jump)
            for (s_col = 0; s_col < size; s_col += jump)
            {
                if (s_row == jump && s_col == jump)
                    continue;
                menger(jump, level, s_col + col, s_row + row);
            }
    return 0;
}

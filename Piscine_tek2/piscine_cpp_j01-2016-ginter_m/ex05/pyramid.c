/*
** pyramid.c for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 19:37:55 2013 maxime ginters
** Last update Wed Jan 09 20:16:45 2013 maxime ginters
*/

#include <stdio.h>

int do_rec(int size, int **map, int row, int col)
{
    if (size == row)
        return 0;
    int left = map[row][col] + do_rec(size, map, row + 1, col);
    int right = map[row][col] = do_rec(size, map, row + 1, col + 1);

    if (left < right)
        return left;
    return right;
}

int pyramid_path(int size, int** map)
{
    return do_rec(size, map, 0, 0);
}


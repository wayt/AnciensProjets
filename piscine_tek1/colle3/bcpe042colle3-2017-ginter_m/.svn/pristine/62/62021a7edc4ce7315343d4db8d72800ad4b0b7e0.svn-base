/*
** colle_searcher.c for bcpe042colle3-2017-ginter_m in /home/fest/Epitech/bcpe042colle3-2017-ginter_m
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Oct 27 19:58:47 2012 maxime ginters
** Last update Sat Oct 27 23:43:52 2012 maxime ginters
*/

#include "utils.h"

int	do_check_for_colle(char **t, int row, int col,
	char (*display)(int, int, int, int))
{
  int	i_row;
  int	i_col;

  i_row = 0;
  while (i_row < row)
  {
    i_col = 0;
    while (i_col < col)
    {
      if (t[i_row][i_col] != (*display)(row, col, i_row, i_col))
        return (0);
      ++i_col;
    }
    ++i_row;
  }
  return (1);
}

int	colle_searcher(char **t, int row, int col)
{
  char	(*display[5])(int, int, int, int);
  int	i;
  int	result;

  display[0] = my_display_colle1_1;
  display[1] = my_display_colle1_2;
  display[2] = my_display_colle1_3;
  display[3] = my_display_colle1_4;
  display[4] = my_display_colle1_5;

  i = 0;
  result = 0;
  while (i < 5)
  {
    if (do_check_for_colle(t, row, col, display[i]) == 1)
      result |= (1 << i);
    ++i;
  }
  return (result);
}

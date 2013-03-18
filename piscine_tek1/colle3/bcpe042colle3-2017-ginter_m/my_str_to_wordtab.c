/*
** str_to_wordtab.c for bcpe042colle3-2017-ginter_m in /home/fest/Epitech/bcpe042colle3-2017-ginter_m
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Oct 27 17:09:19 2012 maxime ginters
** Last update Sat Oct 27 20:44:29 2012 lauris paquit
*/

#include <stdlib.h>
#include "utils.h"

char	**get_malloced_tab(char *str)
{
  int	i;
  char	**t;
  int	size;
  int	row;

  size = 0;
  i = 0;
  while (str[i] != '\0')
    size += (str[i++] == '\n' ? 1 : 0);
  t = malloc((size + 2) * sizeof(char*));
  i = 0;
  size = 0;
  row = 0;
  while (str[i] != '\0')
  {
    ++size;
    if (str[i++] == '\n')
    {
      t[row++] = malloc((size + 1) * sizeof(char));
      size = 0;
    }
  }
  t[row++] = malloc((size + 1) * sizeof(char));
  t[row] = malloc(sizeof(char));
  return (t);
}

char	**my_str_to_wordtab(char *str)
{
  char	**t;
  int	i;
  int	row;
  int	col;

  t = get_malloced_tab(str);
  i = 0;
  row = 0;
  col = 0;
  while (str[i] != '\0')
  {
    if (str[i] != '\n')
      t[row][col++] = str[i];
    else
    {
      t[row][col] = '\0';
      ++row;
      col = 0;
    }
    ++i;
  }
  t[row][col] = '\0';
  t[++row][0] = 0;
  return (t);
}

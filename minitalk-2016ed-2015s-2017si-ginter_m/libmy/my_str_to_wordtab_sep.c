/*
** my_str_to_wordtab2.c for libmy in /home/fest/Epitech/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 03 18:10:03 2012 maxime ginters
** Last update Sun Nov 18 12:49:47 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

char	*dup_sub_str(char *, int, int);

char	**my_str_to_wordtab_sep(char *str, char sep)
{
  char	**t;
  int	i;
  int	prev;
  int	t_i;

  i = 0;
  prev = 0;
  t = NULL;
  t_i = 0;
  while (str[i] != '\0')
  {
    if (str[i++] == sep)
    {
      t = my_realloc(t, t_i + 1, sizeof(char*), t_i * sizeof(char*));
      t[t_i] = dup_sub_str(str, prev, i - 2);
      while (str[i] == sep && str[i] != '\0')
        ++i;
      prev = i;
      ++t_i;
    }
  }
  t = my_realloc(t, t_i + 2, sizeof(char*), t_i * sizeof(char*));
  t[t_i++] = dup_sub_str(str, prev, i - 1);
  t[t_i] = NULL;
  return (t);
}

char	*dup_sub_str(char *str, int from, int to)
{
  char	*buff;
  int	i;

  buff = malloc((to + from + 2) * sizeof(char));
  my_memset(buff, 0x0, to + from + 2);
  i = 0;
  while (from <= to)
    buff[i++] = str[from++];
  return (buff);
}

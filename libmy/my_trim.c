/*
** my_trim.c for libmy in /home/fest/Epitech/Minishell2/libmy
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Nov 27 18:17:34 2012 maxime ginters
** Last update Tue Nov 27 18:20:50 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

char	*my_trim(char *str)
{
  int	from;
  int	to;
  char	*new;

  to = my_strlen(str) - 1;
  from = 0;
  while (str[from] == ' ')
    ++from;
  while (str[to] == ' ')
    --to;
  new = my_substr(str, from, to);
  free(str);
  return (new);
}

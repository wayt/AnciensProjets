/*
** my_revstr.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 09:39:54 2012 maxime ginters
** Last update Tue Nov 06 19:56:38 2012 maxime ginters
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	len;

  i = 0;
  len = my_strlen(str) - 1;
  if (len <= 0)
    return (str);
  while (i < len)
  {
    my_swap_char(str + i, str + len);
    ++i;
    --len;
  }
  return (str);
}

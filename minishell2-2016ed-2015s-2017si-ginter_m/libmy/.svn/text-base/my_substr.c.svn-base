/*
** my_substr.c for libmy in /home/fest/Epitech/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 10 13:49:20 2012 maxime ginters
** Last update Sat Nov 10 14:18:30 2012 maxime ginters
*/

#include "my.h"

char	*my_substr(char *src, int from, int to)
{
  char	*back;
  int	i;

  i = (to - from + 1) + 1;
  back = xmalloc(i * sizeof(char));
  my_memset(back, NULL, i);
  i = 0;
  while (from <= to)
    back[i++] = src[from++];
  return (back);
}

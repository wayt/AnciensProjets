/*
** my_realloc.c for libmy in /home/ginter_m/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 10 11:26:38 2012 maxime ginters
** Last update Sat Nov 10 15:35:26 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

void	*my_memcpy(void *dest, void *src, int size)
{
  char	*d;
  char	*s;
  int	i;

  d = (char*)dest;
  s = (char*)src;
  i = 0;
  while (i++ < size)
  {
    *d = *s;
    ++d;
    ++s;
  }
  return dest;
}

void	*my_realloc(void *src, int size, int type_size, int memset_size)
{
  void	*new;

  new = xmalloc(size * type_size);
  if (src != NULL)
  {
    my_memcpy(new, src, memset_size);
    free(src);
  }

  return (new);
}

/*
** my_strcat.c for ex_01 in /home/ginter_m/Jour_07/ex_01
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 13:16:29 2012 maxime ginters
** Last update Sat Nov 10 15:45:13 2012 maxime ginters
*/

#include "my.h"

char	*my_strcat(char *dest, char *str)
{
  int	size;
  int	i;

  if (!str)
    return (dest);
  i = my_strlen(str);
  if (i == 0)
    return (dest);
  size = my_strlen(dest);
  dest = my_realloc(dest, size + i + 1, sizeof(char), size * sizeof(char));
  i = 0;
  while (str[i] != '\0')
    *(dest + size + i) = *(str + i++);
  *(dest + size + i) = '\0';
  return dest;
}

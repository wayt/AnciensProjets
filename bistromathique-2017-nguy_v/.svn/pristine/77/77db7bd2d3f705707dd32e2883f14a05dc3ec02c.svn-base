/*
** my_strcat.c for ex_01 in /home/ginter_m/Jour_07/ex_01
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 13:16:29 2012 maxime ginters
** Last update Wed Nov 07 16:51:30 2012 maxime ginters
*/

#include "my.h"

char	*my_strcat(char *dest, char *str)
{
  int	size;
  int	i;

  size = my_strlen(dest);
  dest = my_realloc(dest, size + my_strlen(str) + 1, sizeof(char));
  i = 0;
  while (*(str + i) != '\0')
    *(dest + size + i) = *(str + i++);
  *(dest + size + i) = '\0';
  return dest;
}

/*
** my_strdup.c for Jour_08 in /home/ginter_m/Jour_08
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 10 09:32:17 2012 maxime ginters
** Last update Tue Dec 04 20:09:34 2012 vincent leroy
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	len;
  char	*back;

  if (src == NULL)
    return (NULL);
  len = my_strlen(src);
  back = malloc((len + 1) * sizeof(char));
  if (!back)
    return (NULL);
  my_memset(back, 0x0, len + 1);
  my_strcpy(back, src);
  return (back);
}

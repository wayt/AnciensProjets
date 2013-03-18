/*
** my_strdup.c for Jour_08 in /home/ginter_m/Jour_08
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 10 09:32:17 2012 maxime ginters
** Last update Tue Oct 23 18:52:01 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	len;
  char	*back;

  len = my_strlen(src);
  back = malloc((len + 1) * sizeof(char));
  if (!back)
    return (MY_NULL);
  my_strcpy(back, src);
  return (back);
}

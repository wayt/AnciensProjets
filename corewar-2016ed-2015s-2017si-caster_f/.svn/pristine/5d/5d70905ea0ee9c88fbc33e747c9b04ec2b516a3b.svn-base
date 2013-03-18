/*
** my_strcat.c for my_strcat in /home/leroy_v//piscine/Jour_07/exo_01
**
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
**
** Started on  Tue Oct  9 11:23:15 2012 vincent leroy
** Last update Sat Nov 24 18:50:18 2012 vincent leroy
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	taille;

  if (dest != 0 && src != 0)
  {
    taille = my_strlen(dest);
    if (taille == 0)
      return (my_strcpy(dest, src));
    i = 0;
    while (src[i] != '\0')
    {
      dest[i + taille] = src[i];
      i++;
    }
    dest[i + taille] = '\0';
  }
  return (dest);
}

/*
** my_strlen.c for my_strlen in /home/leroy_v//Jour_04/exo03
**
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
**
** Started on  Thu Oct  4 09:40:14 2012 vincent leroy
** Last update Sat Nov 24 18:42:40 2012 vincent leroy
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != 0)
  {
    while (str[i] != '\0')
      i++;
  }
  return (i);
}

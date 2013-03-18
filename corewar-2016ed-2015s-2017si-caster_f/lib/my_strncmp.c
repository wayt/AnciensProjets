/*
** my_strncmp.c for my_strncmp in /home/leroy_v//piscine/Jour_06/exo_06
** 
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
** 
** Started on  Mon Oct  8 11:25:15 2012 vincent leroy
** Last update Thu Dec 13 16:05:52 2012 vincent leroy
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  if (n <= 0)
    return (0);
  if (s1 == 0 && s2 == 0)
    return (0);
  else if (s1 == 0)
    return (-1);
  else if (s2 == 0)
    return (1);
  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && i < n)
  {
    if (s1[i] != s2[i])
      return (s1[i] - s2[i]);
    i++;
  }
  if (i > 0)
    return (s1[i - 1] - s2[i - 1]);
  else
    return (s1[i] - s2[i]);
}

/*
** my_putstr.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 13:46:05 2012 maxime ginters
** Last update Thu Nov 01 17:37:52 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return;
  while (str[i] != '\0')
  {
    write(1, str + i, 1);
    ++i;
  }
}

void	my_putstr_n_free(char *str)
{
  my_putstr(str);
  free(str);
}

void	my_put_double_str(char *str1, char *str2)
{
  my_putstr(str1);
  my_putstr(str2);
}

void	my_put_triple_str(char *str1, char *str2, char *str3)
{
  my_putstr(str1);
  my_putstr(str2);
  my_putstr(str3);
}
void	my_put_x_space_and_double_str(int nb, char *str1, char *str2)
{
  while (nb-- > 0)
    write(1, " ", 1);
  my_putstr(str1);
  my_putstr(str2);
}

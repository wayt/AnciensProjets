/*
** my_power_it.c for libmy in /home/fest/Epitech/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Nov 02 10:46:34 2012 maxime ginters
** Last update Fri Nov 02 10:53:09 2012 maxime ginters
*/

#include "my.h"

int	my_power_it(int nb, int pow)
{
  int	i;
  int	result;

  if (pow == 0)
    return (1);
  i = 1;
  result = nb;
  while (i++ < pow)
    result *= nb;
  return (result);
}

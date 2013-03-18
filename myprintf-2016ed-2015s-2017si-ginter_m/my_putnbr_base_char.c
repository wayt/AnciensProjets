/*
** my_putnbr_base_char.c for libmy in /home/ginter_m/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 13:13:16 2012 maxime ginters
** Last update Fri Oct 12 09:29:44 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

int	get_final_size(int nbr, char *base, char is_neg, int base_size)
{
  int	size;

  size = 0;
  while (nbr > 0)
  {
    nbr /= base_size;
    ++size;
  }

  return (size + (is_neg == 1 ? 2 : 1));
}

char	*my_putnbr_base_char(int nbr, char *base)
{
  int	base_size;
  char	*value;
  int	i;
  char	is_neg;

  value = MY_NULL;
  base_size = my_strlen(base);
  if (base_size <= 0)
    return (MY_NULL);
  i = 0;
  is_neg = (nbr < 0 ? 1 : 0);
  nbr *= (nbr < 0 ? -1 : 1);
  value = malloc(get_final_size(nbr, base, is_neg, base_size) * sizeof(char));
  while (nbr > 0)
  {
    value[i++] = *(base + (nbr % base_size));
    nbr /= base_size;
  }
  if (is_neg == 1)
    value[i++] = '-';
  value[i] = '\0';
  return (my_revstr(value));
}

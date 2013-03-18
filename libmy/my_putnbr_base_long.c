/*
** my_putnbr_base.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 13:13:16 2012 maxime ginters
** Last update Tue Nov 13 18:08:50 2012 maxime ginters
*/

#include "my.h"

ulong	my_putnbr_base_long(ulong nbr, char *base)
{
  int	base_size;
  char	value[1024];
  int	i;
  ulong	my_nbr;

  my_nbr = nbr;
  init_putnbr_base_tab(value);
  base_size = my_strlen(base);
  if (base_size <= 0)
    return (my_nbr);
  i = 0;
  while (nbr > 0)
  {
    value[i++] = *(base + (nbr % base_size));
    nbr /= base_size;
  }
  my_putstr(my_revstr(value));
  return (my_strlen(value));
}

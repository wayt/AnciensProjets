/*
** my_put_nbr.c for work in /home/ginter_m/Jour_03/work
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 03 15:51:24 2012 maxime ginters
** Last update Sun Nov 18 12:48:35 2012 maxime ginters
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	offset;
  char	find;
  char	curr_off;

  offset = 1000000000;
  find = 0;
  curr_off = 0;
  if (nb < 0)
    my_putchar('-');
  else if (nb == 0)
    my_putchar('0');
  while (offset > 0 && nb != 0)
  {
    curr_off = (nb / offset) % (nb < 0 ? -10 : 10);
    if (find == 0)
      if ((curr_off < 0 ? curr_off - (2 * curr_off) : curr_off) > 0)
        find = 1;
    if (find == 1)
      my_putchar('0' + (curr_off < 0 ? curr_off - (2 * curr_off) : curr_off));
    offset /= 10;
  }
}

char	*my_nbr_to_char(int nb)
{
  char	buff[4096];
  int	buff_i;
  int	neg;

  neg = (nb < 0);
  nb *= (nb < 0 ? -1 : 1);
  if (nb == 0)
    return (my_strdup("0"));
  my_memset(buff, 0x0, 4096);
  buff_i = 0;
  while (nb > 0)
  {
    buff[buff_i++] = '0' + (nb % 10);
    nb /= 10;
  }
  buff[buff_i] = '\0';
  if (neg == 1)
    return (my_strcat("-", my_strdup(my_revstr(buff))));
  return (my_strdup(my_revstr(buff)));
}

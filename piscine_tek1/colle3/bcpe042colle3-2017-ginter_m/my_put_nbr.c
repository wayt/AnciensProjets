/*
** my_put_nbr.c for work in /home/ginter_m/Jour_03/work
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 03 15:51:24 2012 maxime ginters
** Last update Sat Oct 27 22:53:46 2012 maxime ginters
*/

#include "utils.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_put_nbr(int nb)
{
  int offset;
  char find;
  char curr_off;

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

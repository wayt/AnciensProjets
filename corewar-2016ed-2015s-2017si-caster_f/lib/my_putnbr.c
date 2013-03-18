/*
** my_putnbr.c for my_put_nbr in /home/leroy_v//Jour_03/exo07
** 
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
** 
** Started on  Wed Oct  3 16:47:55 2012 vincent leroy
** Last update Mon Dec 03 14:44:47 2012 vincent leroy
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_loop_print(int *n, int *pow)
{
  int	res;

  res = 0;
  while (*pow >= 1)
    {
      res++;
      my_putchar(*n / *pow + '0');
      *n %= *pow;
      *pow /= 10;
    }
  return (res);
}

int	my_putnbr(int n)
{
  int	pow;
  int	res;

  res = 0;
  if (n == -2147483648)
    {
      res += my_putnbr(-214748364);
      my_putchar('8');
      return (res + 1);
    }
  else
    {
      if (n < 0)
	{
	  res++;
	  my_putchar('-');
	  n = -n;
	}
      pow = 1;
      while (pow <= n / 10)
	pow *= 10;
      res += my_loop_print(&n, &pow);
    }
  return (res);
}

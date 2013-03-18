/*
** my_power_it.c for Jour_05 in /home/ginter_m/Jour_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 05 10:05:34 2012 maxime ginters
** Last update Fri Oct 05 10:54:13 2012 maxime ginters
*/

#define MAX_INT 0x7FFFFFFF

int	my_power_it(int nb, int power)
{
  int	i;

  i = power;

  if (power == 0 || nb == 0)
    return 0;

  while (--i > 0)
  {
    if (nb > MAX_INT / nb)
      return 0;
    nb *= nb;
  }

  return nb;
}

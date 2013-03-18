/*
** my_factorielle_it.c for Jour_05 in /home/ginter_m/Jour_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 05 09:17:01 2012 maxime ginters
** Last update Tue Oct 09 08:58:55 2012 maxime ginters
*/

#define MAX_INT 0x7FFFFFFF

int	my_factorielle_it(int nb)
{
  int	result;

  result = 1;

  if (nb < 0)
    return 0;

  while (nb >= 1)
  {
    if (result > MAX_INT / nb)
      return 0;
    result *= nb--;
  }

  return result;
}

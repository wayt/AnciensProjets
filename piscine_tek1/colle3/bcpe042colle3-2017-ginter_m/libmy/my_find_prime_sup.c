/*
** my_find_prime_sup.c for Jour_05 in /home/ginter_m/Jour_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 05 16:47:38 2012 maxime ginters
** Last update Tue Oct 09 11:39:09 2012 maxime ginters
*/

#ifndef MAX_INT
  #define MAX_INT 0x7FFFFFFF
#endif

int	my_find_prime_sup(int nb)
{
  if (nb <= 1)
    return 0;
  while (my_is_prime(nb) == 0)
  {
    if (nb >= MAX_INT - 1)
      return 0;
    ++nb;
  }
  return nb;
}

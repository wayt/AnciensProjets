/*
** my_is_prime.c for Jour_05 in /home/ginter_m/Jour_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 05 16:27:07 2012 maxime ginters
** Last update Fri Oct 05 16:47:02 2012 maxime ginters
*/

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  if (nb <= 1)
    return 0;
  while (i < nb)
    if (nb % i++ == 0)
      return 0;
  return 1;
}


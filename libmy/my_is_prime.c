/*
** my_is_prime.c for Jour_05 in /home/ginter_m/Jour_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 05 16:27:07 2012 maxime ginters
** Last update Tue Oct 09 11:34:05 2012 maxime ginters
*/

int	my_is_prime(int nombre)
{
  int	i;

  i = 2;
  if (nombre <= 1)
    return 0;
  while (i < nombre)
    if (nombre % i++ == 0)
      return 0;
  return 1;
}


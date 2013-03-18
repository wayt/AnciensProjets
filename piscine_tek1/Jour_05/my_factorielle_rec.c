/*
** my_factorielle_rec.c for Jour_05 in /home/ginter_m/Jour_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 05 09:48:54 2012 maxime ginters
** Last update Fri Oct 05 11:46:56 2012 maxime ginters
*/

#define MAX_INT 0x7FFFFFFF

int	my_factorielle_rec(int nb)
{
  int	fact;

  if (nb < 0 || nb >= 100000)
    return 0;
  else if (nb <= 1)
    return 1;
  else
  {
    fact = my_factorielle_rec(nb - 1);
    if (fact == 0 || nb > MAX_INT / fact)
      return 0;
    return nb * fact;
  }
}

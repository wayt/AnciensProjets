/*
** my_power_rec.c for Jour_05 in /home/ginter_m/Jour_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 05 10:19:07 2012 maxime ginters
** Last update Tue Oct 09 10:32:38 2012 maxime ginters
*/

#define MAX_INT 0x7FFFFFFF

int	my_power_rec(int nb, int power)
{
  int	var;

  if (power < 0 || power >= 100000)
    return 0;
  else if (power <= 1)
    return 1;
  else
  {
    var = my_power_rec(nb, power - 1);
    if (var == 0 || nb > MAX_INT / var)
      return 0;
    return nb * var;
  }
}

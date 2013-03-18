/*
** my_power_it.c for my in /afs/epitech.net/users/epitech_2016/ginter_m/rendu/lib/my
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 26 10:49:58 2012 maxime ginters
** Last update Fri Oct 26 10:52:34 2012 maxime ginters
*/

int	my_power_it(int v, int p)
{
  int	res;

  if (p == 0)
    return (1);
  res = v;
  while (p-- > 0)
    res *= v;
  return (res);
}

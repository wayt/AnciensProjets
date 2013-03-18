/*
** my_square_root.c for Jour_05 in /home/ginter_m/Jour_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 05 15:21:11 2012 maxime ginters
** Last update Tue Oct 09 11:41:29 2012 maxime ginters
*/

#ifndef MAX_INT
  #define MAX_INT 0x7FFFFFFF
#endif

int	my_square_root(int nb)
{
  int i = 0;

  while (i < MAX_INT)
  {
    if (i > 0 && i > MAX_INT / i)
      return 0;

    if (i * i == nb)
      return i;

    ++i;
  }
  return 0;
}

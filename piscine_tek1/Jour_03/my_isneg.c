/*
** my_isneg.c for  in /home/ginter_m/Jour_03
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.net>
** 
** Started on  Wed Oct 03 12:23:40 2012 maxime ginters
** Last update Tue Oct 09 10:15:37 2012 maxime ginters
*/

int	my_isneg(int nb)
{
  if (nb < 0)
    my_putchar('N');
  else
    my_putchar('P');

  return 0;
}

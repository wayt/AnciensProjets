/*
** my_putchar.c for Jour_03 in /home/ginter_m/Jour_03
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 03 14:21:42 2012 maxime ginters
** Last update Tue Nov 20 15:52:14 2012 maxime ginters
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}

int	my_putchar_int(int c)
{
  write(1, &c, sizeof(int));
  return (1);
}

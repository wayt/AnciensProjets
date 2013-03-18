/*
** my_putchar.c for Jour_03 in /home/ginter_m/Jour_03
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 03 14:21:42 2012 maxime ginters
** Last update Wed Oct 03 14:22:16 2012 maxime ginters
*/

int my_putchar(char c)
{
  write(1, &c, 1);

  return 0;
}

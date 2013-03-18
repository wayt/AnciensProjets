/*
** my_putstr.c for Jour_04 in /home/ginter_m/Jour_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 04 09:00:17 2012 maxime ginters
** Last update Tue Oct 09 10:19:50 2012 maxime ginters
*/

void	my_putstr(char *str)
{
  int	offset;

  offset = 0;
  while (*(str + offset) != '\0')
    my_putchar(*(str + offset++));
}

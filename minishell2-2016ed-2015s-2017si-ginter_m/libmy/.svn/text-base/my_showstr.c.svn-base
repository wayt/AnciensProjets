/*
** my_showstr.c for ex_17 in /home/ginter_m/Jour_06/ex_17
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 16:39:52 2012 maxime ginters
** Last update Tue Oct 09 12:45:51 2012 maxime ginters
*/

void	my_putchar(char c);

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
  {
    if (my_is_printable(*(str + i)) == 1)
      my_putchar(*( str + i));
    else
      my_putnbr_base((int)*(str + i), "0123456789abcdef");
    ++i;
  }

  return (0);
}

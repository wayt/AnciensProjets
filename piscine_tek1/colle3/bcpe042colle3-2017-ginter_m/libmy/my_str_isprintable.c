/*
** my_str_isprintable.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 12:29:09 2012 maxime ginters
** Last update Tue Oct 09 12:41:27 2012 maxime ginters
*/

int	my_is_printable(char c)
{
  if (c >= ' ' && c <= '~')
    return (1);
  return (0);
}

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    if (my_is_printable(*(str + i++)) == 0)
      return (0);
  return (1);
}

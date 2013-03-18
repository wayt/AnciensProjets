/*
** my_str_isnum.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 12:11:17 2012 maxime ginters
** Last update Fri Oct 26 15:48:39 2012 maxime ginters
*/

int	my_isnum(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '-')
    ++i;
  while (*(str + i) != '\0')
    if (my_isnum(*(str + i++)) == 0)
      return (0);

  return (1);
}

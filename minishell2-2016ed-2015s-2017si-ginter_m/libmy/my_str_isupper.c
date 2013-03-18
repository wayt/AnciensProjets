/*
** my_str_isupper.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 12:17:18 2012 maxime ginters
** Last update Tue Oct 09 12:40:54 2012 maxime ginters
*/

int	my_is_upperalpha(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    if (my_is_upperalpha(*(str + i++)) == 0)
      return (0);
  return (1);
}

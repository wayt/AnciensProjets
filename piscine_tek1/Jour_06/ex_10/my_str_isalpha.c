/*
** my_str_isalpha.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 12:03:34 2012 maxime ginters
** Last update Mon Oct 08 12:13:30 2012 maxime ginters
*/

int	my_isalpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    if (my_isalpha(*(str + i++)) == 0)
      return (0);

  return (1);
}

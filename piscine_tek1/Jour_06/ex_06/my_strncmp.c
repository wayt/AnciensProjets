/*
** my_strncmp.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 11:17:16 2012 maxime ginters
** Last update Mon Oct 08 11:27:49 2012 maxime ginters
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  if (n == 0)
    return (0);

  i = 0;
  while (*(s1 + i) == *(s2 + i))
  {
    if (*(s1 + i) == '\0' || i == (n - 1))
      return (0);
    ++i;
  }

  return (*(s1 + i) - *(s2 + i));
}

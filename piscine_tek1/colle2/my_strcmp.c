/*
** my_strcmp.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 10:06:25 2012 maxime ginters
** Last update Sat Oct 13 12:36:45 2012 maxime ginters
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (*(s1 + i) == *(s2 + i))
  {
    if (*(s1 + i) == '\0')
      return (0);
    ++i;
  }

  return (*(s1 + i) - *(s2 + i));
}

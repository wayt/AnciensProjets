/*
** my_strcmp.c for Jour_06 in /home/ginter_m/Jour_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 08 10:06:25 2012 maxime ginters
** Last update Wed Oct 31 14:44:37 2012 maxime ginters
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (my_isalpha(s1[i]) == 0 && s1[i] != '\0')
    ++i;
  while (my_isalpha(s2[j]) == 0 && s2[j] != '\0')
    ++j;
  while (to_lower(s1[i]) == to_lower(s2[j]))
  {
    if (s1[i] == '\0' || s2[j] == '\0')
      return (0);
    ++i;
    ++j;
  }
  return (to_lower(s1[i]) - to_lower(s2[j]));
}

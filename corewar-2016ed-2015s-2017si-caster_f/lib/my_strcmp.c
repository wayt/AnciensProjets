/*
** my_strcmp.c for my_strcmp in /home/leroy_v//piscine/Jour_06/exo_05
** 
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
** 
** Started on  Mon Oct  8 10:09:21 2012 vincent leroy
** Last update Thu Dec 13 16:05:13 2012 vincent leroy
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 == 0 && s2 == 0)
    return (0);
  else if (s1 == 0)
    return (-1);
  else if (s2 == 0)
    return (1);
  i = 0;
  while (s1[i] != '\0')
  {
    if (s1[i] != s2[i])
      return (s1[i] - s2[i]);
    i++;
  }
  return (s1[i] - s2[i]);
}

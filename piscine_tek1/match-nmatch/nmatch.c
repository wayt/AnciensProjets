/*
** nmatch.c for match-nmatch in /home/fest/Epitech/match-nmatch
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sun Oct 14 19:15:29 2012 maxime ginters
** Last update Sun Oct 14 20:04:14 2012 maxime ginters
*/

int	nmatch(char *s1, char *s2)
{
  int	count;
  int	i;
  char	v_match;

  v_match = 0;
  count = 0;
  i = 0;
  while (s1[i] != '\0')
  {
    if (match(s1 + i++, s2) != v_match)
    {
      v_match = !v_match;
      if (v_match == 1)
        ++count;
    }
  }
  return (count);
}

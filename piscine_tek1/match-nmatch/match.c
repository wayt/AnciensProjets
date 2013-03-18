/*
** match.c for match-nmatch in /home/ginter_m/match-nmatch
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 15:50:50 2012 maxime ginters
** Last update Sun Oct 14 20:04:12 2012 maxime ginters
*/

#include "my.h"

int	char_match(char c, char match)
{
  if (c == match)
    return (0);
  if (match == '*')
    return (1);
  return (-1);
}

void	avance_match(char *str, int *j)
{
  while (str[*j] == '*' && str[*j + 1] == '*')
    ++*j;
}

int	match(char *str, char *match)
{
  int	i;
  int	j;
  int	m_res;

  i = 0;
  j = 0;
  while (str[i] != '\0' && match[j] != '\0')
  {
    avance_match(match, &j);
    m_res = char_match(str[i], match[j]);
    if (m_res == -1)
      return (0);
    if (m_res == 0)
      ++j;
    else if (m_res == 1)
      if (match[j + 1] == '\0')
        return (1);
      else if (char_match(str[i], match[j + 1]) == 0)
        j += 2;
    ++i;
  }
  avance_match(match, &j);
  if (str[i] == '\0' && match[j] == '*' && match[j + 1] == '\0')
    return (1);
  return (match[j] == '\0' ? 1 : 0);
}


/*
** my_str_to_wordtab.c for my_sh in /home/leroy_v//Epitech/my_sh
** 
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
** 
** Started on  Sat Nov  3 12:36:29 2012 vincent leroy
** Last update Tue Dec 04 11:15:52 2012 vincent leroy
*/

#include <stdlib.h>
#include "my.h"

int	check_sepa(char c, char *sepa)
{
  int	i;

  i = 0;
  while (sepa[i] != '\0')
    if (sepa[i++] == c)
      return (1);
  return (0);
}

int	count_word(char *str, char *sepa)
{
  int	i;
  int	word;

  i = 0;
  word = 1;
  while (str[i] != '\0')
  {
    if (check_sepa(str[i], sepa) == 1)
    {
      word++;
      while (str[i] != '\0' && check_sepa(str[i], sepa) == 1)
	i++;
      if (str[i] == '\0')
	i--;
    }
    i++;
  }
  return (word);
}

int	len_of_word(char *str, int dep, char *sepa)
{
  int	i;

  i = dep;
  while (str[i] != '\0' && check_sepa(str[i], sepa) == 0)
    i++;
  return (i - dep);
}

char	*get_word(char *str, char *sepa, int word)
{
  int	i;
  int	count;
  int	len;
  char	*c;

  i = 0;
  count = 1;
  while (str[i] != '\0' && count <= word)
  {
    if (check_sepa(str[i], sepa) == 1)
    {
      count++;
      while (check_sepa(str[i], sepa) == 1 && str[i] != '\0')
	i++;
      i--;
    }
    i++;
  }
  len = len_of_word(str, i, sepa);
  if ((c = malloc(len + 1)) == NULL)
    return (NULL);
  my_memset(c, 0, len + 1);
  my_strncpy(c, str + i, len);
  return (c);
}

char	**my_str_to_wordtab(char *str, char *sepa)
{
  char	**tab;
  int	word;
  int	i;

  if (str == NULL)
  {
    if ((tab = malloc(sizeof(char*))) == NULL)
      return (NULL);
    my_memset(tab, 0, sizeof(char*));
    return (tab);
  }
  while (*str != '\0' && check_sepa(*str, sepa) == 1)
    str++;
  word = count_word(str, sepa);
  if ((tab = malloc((word + 1) * sizeof(char*))) == NULL)
    return (NULL);
  my_memset(tab, 0, (word + 1) * sizeof(char*));
  i = 0;
  while (i < word)
  {
    tab[i] = get_word(str, sepa, i);
    i++;
  }
  tab[i] = NULL;
  return (tab);
}

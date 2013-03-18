/*
** my_advanced_sort_wordtab.c for ex_04 in /home/fest/Epitech/Jour_11/ex_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 15:00:00 2012 maxime ginters
** Last update Tue Oct 23 15:04:55 2012 maxime ginters
*/

#include "my.h"

int	my_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
{
  char	*temp;
  char	i;
  char	j;

  i = 0;
  while (tab[i][0] != 0)
  {
    j = 0;
    while (tab[j][0] != 0)
    {
      if ((*cmp)(tab[i], tab[j]) < 0)
      {
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
      }
      ++j;
    }
    ++i;
  }
  return (0);
}

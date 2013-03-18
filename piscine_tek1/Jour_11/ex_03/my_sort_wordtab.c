/*
** my_sort_wordtab.c for ex_03 in /home/fest/Epitech/Jour_11/ex_03
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 14:18:00 2012 maxime ginters
** Last update Tue Oct 23 18:17:46 2012 maxime ginters
*/

#include "my.h"

int	my_sort_wordtab(char **tab)
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
      if (my_strcmp(tab[i], tab[j]) < 0)
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

/*
** my_sort_char_tab.c for libmy in /home/fest/Epitech/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 29 19:50:26 2012 maxime ginters
** Last update Wed Oct 31 13:51:10 2012 maxime ginters
*/

#include "my.h"

void	my_sort_char_tab(char **t, int reverse)
{
  int	i;
  int	j;
  char	*temp;
  int	cmp;

  i = 0;
  while (t[i][0] != 0)
  {
    j = 0;
    while (t[j][0] != 0)
    {
      cmp = my_strcmp(t[i], t[j]);
      if ((cmp < 0 && reverse == 0) || (cmp > 0 && reverse == 1))
      {
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
      }
      ++j;
    }
    ++i;
  }
}

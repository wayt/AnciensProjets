/*
** my_show_wordtab.c for ex_05 in /home/ginter_m/Jour_08/ex_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 10 16:13:55 2012 maxime ginters
** Last update Wed Oct 10 16:45:28 2012 maxime ginters
*/

#include "my.h"

char	**my_str_to_wordtab(char *);

int	my_show_wordtab(char **tab)
{
  int	i;

  if (tab == MY_NULL)
    return (0);
  i = 0;
  while (tab[i][0] != 0)
  {
    my_putstr(tab[i++]);
    my_putchar('\n');
  }
  return (0);
}

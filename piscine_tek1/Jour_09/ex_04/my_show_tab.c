/*
** my_show_tab.c for ex_04 in /home/fest/Epitech/Jour_09/ex_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 11 14:32:54 2012 maxime ginters
** Last update Fri Oct 12 09:47:48 2012 maxime ginters
*/

#include "my.h"

int	my_show_tab(struct s_stock_par *par)
{
  int	i;

  i = 0;
  while (par[i].str != 0)
  {
    my_putstr(par[i].str);
    my_putchar('\n');
    my_put_nbr(par[i].size_param);
    my_putchar('\n');
    my_show_wordtab(par[i].tab);
    ++i;
  }

  return (0);
}

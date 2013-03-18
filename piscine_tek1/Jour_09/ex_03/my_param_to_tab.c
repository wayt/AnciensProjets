/*
** my_param_to_tab.c for ex_03 in /home/fest/Epitech/Jour_09/ex_03
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 11 12:43:48 2012 maxime ginters
** Last update Fri Oct 12 09:47:02 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

struct	s_stock_par
{
  int	size_param;
  char	*str;
  char	*copy;
  char	**tab;
};

typedef struct s_stock_par t_stock_par;

struct s_stock_par	*my_param_to_tab(int ac, char **av)
{
  t_stock_par	*t;
  int	i;

  t = malloc((ac + 1) * sizeof(t_stock_par));
  i = 0;
  while (i < ac)
  {
    t[i].size_param = my_strlen(av[i]);
    t[i].str = *(av + i);
    t[i].copy = my_strdup(av[i]);
    t[i].tab = my_str_to_wordtab(av[i]);

    ++i;
  }
  t[i].str = MY_NULL;
  return (t);
}

/*
** free_tab.c for lib in /home/leroy_v/github/CoreWar/lib
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Wed Dec 05 15:44:17 2012 vincent leroy
** Last update Thu Dec 06 12:49:04 2012 fabien casters
*/

#include <stdlib.h>
#include "my.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}

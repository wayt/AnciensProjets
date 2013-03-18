/*
** clean_wordtab.c for libmy in /home/fest/Epitech/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Nov 05 11:33:15 2012 maxime ginters
** Last update Mon Nov 05 11:58:29 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

void	clean_wordtab(char **t)
{
  int	i;

  i = 0;
  while (t[i])
    free(t[i++]);
  free(t);
}

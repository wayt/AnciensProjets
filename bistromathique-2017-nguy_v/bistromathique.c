/*
** bistromathique.c for bistromathique in /home/fest/Epitech/bistromathique
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Nov 05 18:35:22 2012 maxime ginters
** Last update Tue Nov 06 18:41:52 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

t_base	*formate_base(char *str)
{
  t_base	*base;
  int	i;

  base = malloc(sizeof(t_base));
  if (base == NULL)
  {
    my_putstr("Error : can't malloc\n");
    exit(1);
  }
  base->length = my_strlen(str);
  base->str = my_strdup(str);
  my_memset(base->value, -1, 255);
  i = 0;
  while (str[i] != '\0')
    base->value[str[i]] = i++;
  return (base);
}

void	free_base(t_base *b)
{
  free(b->str);
  free(b);
}

void	formate_operator(char *str, char ops[7])
{
  int	i;

  i = 0;
  while (str[i] != '\0' && i < 7)
    ops[i] = str[i++];
}

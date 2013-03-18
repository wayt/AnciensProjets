/*
** my_params_in_list.c for Epitech in /home/fest/Epitech
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 18:31:51 2012 maxime ginters
** Last update Tue Oct 23 19:07:40 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

t_list	*my_params_in_list(int ac, char **av)
{
  int	i;

  t_list	*prev;
  t_list	*first;

  i = 0;
  prev = MY_NULL;
  first = MY_NULL;
  while (i < ac)
  {
    t_list	*new;
    new = malloc(sizeof(t_list));
    new->data = my_strdup(av[i]);
    new->next = MY_NULL;
    if (prev != MY_NULL)
      prev->next = new;
    prev = new;
    if (first == MY_NULL)
      first = new;
    ++i;
  }
  return (first);
}

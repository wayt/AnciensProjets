/*
** create_list.c for list in /home/fest/Epitech/MySelect/list
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Nov 19 11:30:39 2012 maxime ginters
** Last update Wed Nov 21 14:28:02 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

void	init_list_elem(t_list *elem, char *str)
{
  elem->next = NULL;
  elem->str = my_strdup(str);
  elem->selected = 0;
  elem->focus = 0;
}

t_list	*create_list(int size, char **str)
{
  t_list	*itr;
  t_list	*first;
  t_list	*prev;
  int		i;

  first = xmalloc(sizeof(t_list));
  init_list_elem(first, str[0]);
  first->focus = 1;
  prev = NULL;
  i = 1;
  while (i < size)
  {
    itr = xmalloc(sizeof(t_list));
    init_list_elem(itr, str[i]);
    if (prev == NULL)
      first->next = itr;
    else
      prev->next = itr;
    prev = itr;
    ++i;
  }
  return (first);
}

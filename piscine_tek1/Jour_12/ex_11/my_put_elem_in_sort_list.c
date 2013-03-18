/*
** my_put_elem_in_sort_list.c for ex_11 in /home/fest/Epitech/Jour_12/ex_11
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 24 12:38:20 2012 maxime ginters
** Last update Wed Oct 24 12:49:39 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

int	my_sort_list(t_list **, int *);

int	my_put_elem_in_sort_list(t_list **begin, void *data, int (*cmp)())
{
  t_list	*ptr
  t_list	*new;

  ptr = *begin;
  while (ptr-next != MY_NULL)
    ptr = ptr->next;
  new = malloc(sizeof(t_list));
  new->data = data;
  ptr->next = new;
  return (my_sort_list(begin, cmp));
}

/*
** my_add_sort_list_to_sort_list.c for ex_12 in /home/fest/Epitech/Jour_12/ex_12
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 24 12:45:20 2012 maxime ginters
** Last update Wed Oct 24 12:49:17 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

int	my_sort_list(t_list **, int *);

int	my_add_sort_list_to_sort_list(t_list **b1, t_list *2, int (*cmp)())
{
  t_list	*ptr

  ptr = *b1;
  while (ptr-next != MY_NULL)
    ptr = ptr->next;
  t_list	*new;
  ptr->next = b2;
  return (my_sort_list(b1, cmp));
}

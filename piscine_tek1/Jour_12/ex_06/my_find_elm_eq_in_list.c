/*
** my_find_elm_eq_in_list.c for ex_06 in /home/fest/Epitech/Jour_12/ex_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 20:26:09 2012 maxime ginters
** Last update Tue Oct 23 20:48:17 2012 maxime ginters
*/

#include "my.h"
#include "mylist.h"

void	*my_find_elm_eq_in_list(t_list *begin, void *data_ref, int (*cmp)())
{
  t_list	*list_ptr;

  list_ptr = begin;
  while (list_ptr != MY_NULL)
  {
    if ((*cmp)(*list_ptr->data, data_ref) == 0)
      return (list_ptr->data);
    list_ptr = list_ptr->next;
  }
  return (MY_NULL);
}

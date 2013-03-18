/*
** my_rm_all_eq_from_list.c for ex_08 in /home/fest/Epitech/Jour_12/ex_08
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 20:52:30 2012 maxime ginters
** Last update Tue Oct 23 21:06:42 2012 maxime ginters
*/

#include "my.h"
#include "mylist.h"

int	my_rm_all_eq_from_list(t_list **begin, void *data_ref, int (*cmp)())
{
  t_list	*list_ptr;
  t_list	*prev;

  prev = MY_NULL;
  list_ptr = *begin;
  while (list_ptr != MY_NULL)
  {
    if ((*cmp)(list_ptr->data, data_ref) == 0)
    {
      if (prev != MY_NULL)
        prev->next = list_ptr->next;
      else
        (*begin) = list_ptr->next;
    }
    else
      prev = list_ptr;
    list_ptr = list_ptr->next;
  }
  return (0);
}

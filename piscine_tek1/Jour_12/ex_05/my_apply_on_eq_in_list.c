/*
** my_apply_on_eq_in_list.c for ex_05 in /home/fest/Epitech/Jour_12/ex_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 20:20:14 2012 maxime ginters
** Last update Tue Oct 23 20:25:12 2012 maxime ginters
*/

#include "listmy.h"
#include "my.h"

int	my_apply_on_eq_in_list(t_list *b, int(*f)(), void *ref, int (*cmp)())
{
  t_list	*list_ptr;

  list_ptr = b;
  while (list_ptr != MY_NULL)
  {
    if ((*cmp)(list_ptr->data, ref) == 0)
      (*f)(list_ptr->data);
    list_ptr = list_ptr->next;
  }
  return (0);
}

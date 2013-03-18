/*
** my_add_list_to_list.c for ex_09 in /home/fest/Epitech/Jour_12/ex_09
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 21:08:32 2012 maxime ginters
** Last update Tue Oct 23 21:12:12 2012 maxime ginters
*/

#include "listmy.h"
#include "my.h"

int	my_add_list_to_list(t_list **begin1, t_list *begin2)
{
  t_list	*list_ptr;

  list_ptr = *begin1;
  while (list_ptr->next != MY_NULL)
    list_ptr = list_ptr->next;
  list_ptr->next = begin2;
  return (0);
}

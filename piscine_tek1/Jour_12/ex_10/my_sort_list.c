/*
** my_sort_list.c for ex_10 in /home/fest/Epitech/Jour_12/ex_10
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 21:13:52 2012 maxime ginters
** Last update Wed Oct 24 12:32:45 2012 maxime ginters
*/

#include "my.h"
#include "mylist.h"

int	my_sort_list(t_list **begin, int (*cmp)())
{
  t_list	*list_i;
  t_list	*list_j;
  void	*data;

  list_i = *begin;
  while (list_i != MY_NULL)
  {
    list_j = *begin;
    while (list_j != MY_NULL)
    {
      if ((*cmp)(list_i->data, list_j->data) < 0)
      {
        data = list_i->data;
        list_i->data = list_j->data;
        list_j->data = data;
      }
      list_j = list_j->next;
    }
    list_i = list_i->next;
  }
  return (0);
}

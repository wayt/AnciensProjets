/*
** my_list_size.c for ex_02 in /home/fest/Epitech/Jour_12/ex_02
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 19:09:06 2012 maxime ginters
** Last update Tue Oct 23 19:12:08 2012 maxime ginters
*/

#include "mylist.h"
#include "my.h"

int	my_list_size(t_list *begin)
{
  int	size;
  t_list	*ptr;

  size = 0;
  ptr = begin;
  while (ptr != MY_NULL)
  {
    ++size;
    ptr = ptr->next;
  }
  return (size);
}

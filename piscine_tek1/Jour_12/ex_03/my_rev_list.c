/*
** my_rev_list.c for ex_03 in /home/fest/Epitech/Jour_12/ex_03
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 19:16:19 2012 maxime ginters
** Last update Tue Oct 23 19:34:13 2012 maxime ginters
*/

#include "mylist.h"
#include "my.h"

int	my_rev_list(t_list **begin)
{
  t_list	*prev;
  t_list	*current;

  prev = MY_NULL;
  current = MY_NULL;
  if (begin == MY_NULL)
    return (-1);
  current = *begin;
  while (current != MY_NULL)
  {
    t_list	*next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *begin = prev;
  return (0);
}

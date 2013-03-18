/*
** find_list.c for list in /home/fest/Epitech/MySelect/list
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Nov 20 16:21:51 2012 maxime ginters
** Last update Thu Nov 22 18:54:51 2012 maxime ginters
*/

#include "list.h"

t_list	*get_elem_at_index(t_list *list, unsigned int index)
{
  t_list	*itr;
  int	i;

  itr = list;
  i = 0;
  while (itr)
  {
    if (i++ == index)
      return (itr);
    itr = itr->next;
  }
  return (NULL);
}

t_list	*get_focus_elem(t_list *list)
{
  while (list)
  {
    if (list->focus == 1)
      return (list);
    list = list->next;
  }
  return (NULL);
}

int	get_max_strlen(t_list *list)
{
  int	max;
  int	tmp;

  max = 0;
  while (list)
  {
    tmp = my_strlen(list->str);
    if (tmp > max)
      max = tmp;
    list = list->next;
  }
  return (max);
}

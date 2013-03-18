/*
** stdlistsearch.c for dll in /home/leroy_v/Epitech/linked_list/dll
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Nov 17 17:39:13 2012 vincent leroy
** Last update Tue Dec 04 20:06:25 2012 vincent leroy
*/

#include "stdlist.h"

int	replace_elm(t_list *list, void *data, int pos, void (*freedata)())
{
  int	res;

  if (list == NULL || pos >= list->nb_elm || pos < 0)
    return (1);
  res = del_elm(list, pos, freedata);
  if (res != 0)
    return (res);
  res = insert_elm(list, data, pos);
  return (res);
}

int	__search_loop_elm(t_list *list, t_elm *to_find)
{
  t_elm	*next;
  t_elm	*prev;
  int	i;
  int	j;

  next = list->first;
  prev = list->last;
  i = 0;
  j = list->nb_elm - 1;
  while (next != list->last)
  {
    if (next == to_find)
      return (i);
    else if (prev == to_find)
      return (j);
    next = next->next;
    if (next == prev)
      return (next == to_find ? i : -1);
    prev = prev->prev;
    i++;
    j--;
  }
  return (-1);
}

int	search_elm(t_list *list, t_elm *to_find)
{
  if (list == NULL || to_find == NULL)
    return (-2);
  if (list->first == to_find)
    return (0);
  return (__search_loop_elm(list, to_find));
}

int	__search_loop_data(t_list *list, void *data_ref, int (*cmp)())
{
  t_elm	*next;
  t_elm	*prev;
  int	i;
  int	j;

  next = list->first;
  prev = list->last;
  i = 0;
  j = list->nb_elm - 1;
  while (next != list->last)
  {
    if (cmp(next->data, data_ref) == 0)
      return (i);
    else if (cmp(prev->data, data_ref) == 0)
      return (j);
    next = next->next;
    if (next == prev)
      return (cmp(next->data, data_ref) == 0 ? i : -1);
    prev = prev->prev;
    i++;
    j--;
  }
  return (-1);
}

int	search_data(t_list *list, void *data_ref, int (*cmp)())
{
  if (list == NULL || cmp == NULL)
    return (-2);
  if (list->first == NULL)
    return (-1);
  if (cmp(list->first->data, data_ref) == 0)
    return (0);
  return (__search_loop_data(list, data_ref, cmp));
}

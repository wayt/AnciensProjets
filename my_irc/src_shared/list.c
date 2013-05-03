/*
** list.c for src_shared in /Storage/Epitech/my_irc/src_shared
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 22 11:33:21 2013 maxime ginters
** Last update Sun Apr 28 18:17:28 2013 maxime ginters
*/

#include <stdlib.h>
#include "list.h"

void* list_get_elem_at_back(t_list list)
{
  if (list == NULL)
    return NULL;
  while (list->next != NULL)
    list = list->next;
  return list->value;
}

void* list_get_elem_at_position(t_list list, unsigned int position)
{
  unsigned int i;

  if (list == NULL)
    return NULL;
  if (position == 0)
    return list_get_elem_at_front(list);
  i = 0;
  while (i != position && list != NULL)
  {
    ++i;
    list = list->next;
  }
  if (i != position || list == NULL)
    return NULL;
  return list->value;
}

t_node* list_get_first_node_with_value(t_list list, void* value,
    t_value_comparator val_comp)
{
  while (list != NULL)
  {
    if ((val_comp)(list->value, value) == 0)
      return list;
    list = list->next;
  }
  return NULL;
}

void list_clear(t_list* front_ptr)
{
  t_list	list;
  t_list	tmp;

  list = *front_ptr;
  while (list)
  {
    tmp = list->next;
    free(list);
    list = tmp;
  }
  *front_ptr = NULL;
}

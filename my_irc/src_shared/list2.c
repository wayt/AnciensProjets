/*
** list2.c for src_shared in /home/fest/Epitech/my_irc/src_shared
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:16:14 2013 maxime ginters
** Last update Sun Apr 28 18:18:11 2013 maxime ginters
*/

#include <stdlib.h>
#include "list.h"

unsigned int list_get_size(t_list list)
{
  unsigned int count = 0;
  while (list != NULL)
  {
    ++count;
    list = list->next;
  }
  return count;
}

t_bool list_is_empty(t_list list)
{
  return (list == NULL ? LTRUE : LFALSE);
}

void list_dump(t_list list, t_value_displayer val_disp)
{
  while (list != NULL)
  {
    (val_disp)(list->value);
    list = list->next;
  }
}

t_bool list_add_elem_at_front(t_list* front_ptr, void* elem)
{
  t_list new_elem;

  if ((new_elem = malloc(sizeof(t_node))) == NULL)
    return LFALSE;
  new_elem->next = *front_ptr;
  *front_ptr = new_elem;
  new_elem->value = elem;
  return LTRUE;
}

t_bool list_add_elem_at_back(t_list* front_ptr, void* elem)
{
  t_list last_elem;
  t_list new_elem;

  last_elem = *front_ptr;
  if (last_elem != NULL)
    while (last_elem->next != NULL)
      last_elem = last_elem->next;
  if ((new_elem = malloc(sizeof(t_node))) == NULL)
    return LFALSE;
  new_elem->value = elem;
  new_elem->next = NULL;
  if (last_elem)
    last_elem->next = new_elem;
  else
    *front_ptr = new_elem;
  return LTRUE;
}

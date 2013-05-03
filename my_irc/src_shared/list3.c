/*
** list3.c for src_shared in /home/fest/Epitech/my_irc/src_shared
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 28 18:16:45 2013 maxime ginters
** Last update Sun Apr 28 18:17:12 2013 maxime ginters
*/

#include <stdlib.h>
#include "list.h"

t_bool list_add_elem_at_position(t_list* front_ptr, void* elem,
    unsigned int position)
{
  unsigned int i;
  t_list prev_elem;
  t_list new_elem;

  if (position == 0)
    return list_add_elem_at_front(front_ptr, elem);
  if (*front_ptr == NULL)
    return LFALSE;

  if ((new_elem = malloc(sizeof(t_node))) == NULL)
    return LFALSE;
  new_elem->value = elem;

  prev_elem = *front_ptr;
  i = 1;
  while (prev_elem->next != NULL && i != position)
  {
    ++i;
    prev_elem = prev_elem->next;
  }
  prev_elem->next = new_elem;
  return LTRUE;
}

t_bool list_del_elem_at_front(t_list* front_ptr)
{
  if (*front_ptr == NULL)
    return LFALSE;
  *front_ptr = (*front_ptr)->next;
  if (*front_ptr == NULL)
    return LFALSE;
  return LTRUE;
}

t_bool list_del_elem_at_back(t_list* front_ptr)
{
  t_list new_last;

  if (*front_ptr == NULL)
    return LFALSE;
  if ((*front_ptr)->next == NULL)
  {
    *front_ptr = NULL;
    return LFALSE;
  }
  new_last = *front_ptr;
  while (new_last->next->next)
    new_last = new_last->next;
  new_last->next = NULL;
  return LTRUE;
}

t_bool list_del_elem_at_position(t_list* front_ptr,
    unsigned int position)
{
  unsigned int i;
  t_list elem;

  if (position == 0)
    return list_del_elem_at_front(front_ptr);

  if (*front_ptr == NULL)
    return LFALSE;
  elem = *front_ptr;
  i = 1;
  while (i != position && elem->next)
  {
    ++i;
    elem = elem->next;
  }
  if (i != position || elem->next == NULL)
    return LFALSE;
  elem->next = elem->next->next;
  return LTRUE;
}

void* list_get_elem_at_front(t_list list)
{
  if (list == NULL)
    return NULL;
  return list->value;
}


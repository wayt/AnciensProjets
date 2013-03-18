/*
** stdlistrm.c for dll in /home/leroy_v/Epitech/linked_list/dll
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Nov 17 15:26:23 2012 vincent leroy
** Last update Tue Dec 04 20:04:07 2012 vincent leroy
*/

#include "stdlist.h"

int	del_first_elm(t_list *list, void (*freedata)())
{
  t_elm	*rm;

  if (list == NULL)
    return (1);
  rm = list->first;
  list->nb_elm--;
  if (list->nb_elm == 0)
  {
    list->last = NULL;
    list->first = NULL;
    if (freedata != NULL)
      freedata(rm->data);
    free(rm);
    return (0);
  }
  list->first = rm->next;
  list->first->prev = list->last;
  list->last->next = list->first;
  if (freedata != NULL)
    freedata(rm->data);
  free(rm);
  return (0);
}

int	del_last_elm(t_list *list, void (*freedata)())
{
  t_elm	*rm;

  if (list == NULL)
    return (1);
  rm = list->last;
  list->nb_elm--;
  if (list->nb_elm == 0)
  {
    list->last = NULL;
    list->first = NULL;
    if (freedata != NULL)
      freedata(rm->data);
    free(rm);
    return (0);
  }
  list->last = rm->prev;
  list->last->next = list->first;
  list->first->prev = list->last;
  if (freedata != NULL)
    freedata(rm->data);
  free(rm);
  return (0);
}

int	del_elm(t_list *list, int pos, void (*freedata)())
{
  t_elm	*rm;

  if (list == NULL || pos >= list->nb_elm || pos < 0)
    return (1);
  if ((rm = get_elm(list, pos)) == NULL)
    return (3);
  rm->next->prev = rm->prev;
  rm->prev->next = rm->next;
  if (freedata != NULL)
    freedata(rm->data);
  free(rm);
  list->nb_elm--;
  return (0);
}

int	del_all_list(t_list **list, void (*freeelm)(), void (*freelist)())
{
  int	res;

  if (list == NULL || *list == NULL)
    return (1);
  while ((*list)->nb_elm > 0)
    if ((res = del_last_elm(*list, freeelm)) != 0)
      return (res);
  if (freelist != NULL)
    freelist((*list)->data);
  free(*list);
  *list = NULL;
  return (0);
}

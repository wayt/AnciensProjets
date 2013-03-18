/*
** stdlistadd.c for dll in /home/leroy_v/Epitech/linked_list/dll
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Nov 17 15:23:02 2012 vincent leroy
** Last update Wed Nov 21 20:26:33 2012 vincent leroy
*/

#include "stdlist.h"

int	add_first_elm(t_list *list, void *data)
{
  t_elm	*elm;

  if (list == NULL)
    return (1);
  if ((elm = malloc(sizeof(t_elm))) == NULL)
    return (2);
  list->nb_elm++;
  elm->data = data;
  if (list->nb_elm == 1)
  {
    list->first = elm;
    list->last = elm;
    elm->next = elm;
    elm->prev = elm;
    return (0);
  }
  list->first->prev = elm;
  elm->next = list->first;
  list->first = elm;
  list->last->next = elm;
  elm->prev = list->last;
  return (0);
}

int	add_last_elm(t_list *list, void *data)
{
  t_elm	*elm;

  if (list == NULL)
    return (1);
  if ((elm = malloc(sizeof(t_elm))) == NULL)
    return (2);
  list->nb_elm++;
  elm->data = data;
  if (list->nb_elm == 1)
  {
    list->first = elm;
    list->last = elm;
    elm->next = elm;
    elm->prev = elm;
    return (0);
  }
  list->last->next = elm;
  elm->prev = list->last;
  list->last = elm;
  list->first->prev = elm;
  elm->next = list->first;
  return (0);
}

int	insert_elm(t_list *list, void *data, int pos)
{
  t_elm	*elm;
  t_elm	*new;

  if (list == NULL || pos >= list->nb_elm || pos < 0)
    return (1);
  if (pos == list->nb_elm - 1)
    return (add_last_elm(list, data));
  else if (pos == 0)
    return (add_first_elm(list, data));
  if ((elm = get_elm(list, pos)) == NULL)
    return (3);
  if ((new = malloc(sizeof(t_elm))) == NULL)
    return (2);
  new->data = data;
  new->prev = elm->prev;
  elm->prev->next = new;
  elm->prev = new;
  new->next = elm;
  list->nb_elm++;
  return (0);
}

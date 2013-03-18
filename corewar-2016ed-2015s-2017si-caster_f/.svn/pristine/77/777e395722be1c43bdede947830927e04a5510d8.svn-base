/*
** stdlist.c for dll in /home/leroy_v/Epitech/linked_list/dll
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Nov 17 10:10:11 2012 vincent leroy
** Last update Wed Nov 21 20:22:58 2012 vincent leroy
*/

#include "stdlist.h"

t_list		*create_list(void *data)
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->data = data;
  list->nb_elm = 0;
  list->first = NULL;
  list->last = NULL;
  return (list);
}

t_elm	*__get_elm_last(t_list *list, int pos)
{
  t_elm	*elm;
  int	i;

  i = 0;
  elm = list->last;
  while (elm != list->first)
  {
    if (i++ == (list->nb_elm - pos - 1))
      return (elm);
    elm = elm->prev;
  }
  return (NULL);
}

t_elm	*__get_elm_first(t_list *list, int pos)
{
  t_elm	*elm;
  int	i;

  i = 0;
  elm = list->first;
  while (elm != list->last)
  {
    if (i++ == pos)
      return (elm);
    elm = elm->next;
  }
  return (NULL);
}

t_elm	*get_elm(t_list *list, int pos)
{
  if (list == NULL || pos >= list->nb_elm || pos < 0)
    return (NULL);
  if (pos == list->nb_elm)
    return (list->last);
  if (pos == 0)
    return (list->first);
  if (pos >= list->nb_elm / 2)
    return (__get_elm_last(list, pos));
  else
    return (__get_elm_first(list, pos));
}

void	*get_data(t_list *list, int pos)
{
  t_elm	*elm;

  if ((elm = get_elm(list, pos)) == NULL)
    return (NULL);
  return (elm->data);
}

/*
** list_utils.c for list in /home/fest/Epitech/MySelect/list
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Nov 20 17:51:45 2012 maxime ginters
** Last update Wed Nov 21 17:43:21 2012 maxime ginters
*/

#include "list.h"

int	get_cursor_pos(t_list *list)
{
  int	i;

  i = 0;
  while (list)
  {
    if (list->focus == 1)
      return (i);
    ++i;
    list = list->next;
  }
  return (0);
}

int	get_list_size(t_list *list)
{
  int	i;

  i = 0;
  while (list)
  {
    ++i;
    list = list->next;
  }
  return (i);
}

t_list	*get_last(t_list *list)
{
  if (!list)
    return (NULL);
  while (list->next)
    list = list->next;
  return (list);
}
void	up_focus(t_list *list)
{
  t_list	*prev;

  prev = NULL;
  while (list)
  {
    if (list->focus == 1)
    {
      if (prev)
        prev->focus = 1;
      else if ((prev = get_last(list)) != NULL)
        prev->focus = 1;
      list->focus = 0;
      return;
    }
    prev = list;
    list = list->next;
  }
}

void	down_focus(t_list *list)
{
  t_list	*first;

  first = list;
  while (list)
  {
    if (list->focus == 1)
    {
      list->focus = 0;
      if (list->next)
        list->next->focus = 1;
      else
        first->focus = 1;
      return;
    }
    list = list->next;
  }
}

/*
** free_list.c for list in /home/fest/Epitech/MySelect/list
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Nov 19 11:57:25 2012 maxime ginters
** Last update Fri Nov 23 19:42:15 2012 maxime ginters
*/

#include <stdlib.h>
#include "list.h"

void	free_list(t_list *list)
{
  t_list	*itr;
  t_list	*tmp;

  if (!list)
    return;
  itr = list;
  while (itr->next)
  {
    tmp = itr->next;
    free(itr->str);
    free(itr);
    itr = tmp;
  }
  free(itr->str);
  free(itr);
}
void	set_focused(t_list* l1, t_list *l2)
{
  if (l1)
    l1->focus = 1;
  else if (l2)
    l2->focus = 1;
}

void	remove_focused_item(t_list **list)
{
  t_list	*prev;
  t_list	*itr;

  if (!(*list))
    return;
  prev = NULL;
  itr = *list;
  if ((*list)->focus == 1 && (*list)->next == NULL)
    exit_error("The list is empty...\n");
  while (itr)
  {
    if (itr->focus == 1)
    {
      if (prev)
        prev->next = itr->next;
      else
        *list = itr->next;
      set_focused(itr->next, *list);
      free(itr->str);
      free(itr);
      return;
    }
    prev = itr;
    itr = itr->next;
  }
}

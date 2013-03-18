/*
** stdlistsort.c for dll in /home/leroy_v/Epitech/linked_list/dll
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Nov 17 17:19:18 2012 vincent leroy
** Last update Sat Nov 17 17:34:26 2012 leroy_v
*/

#include "stdlist.h"

void	__swap_elm(t_elm *elm1, t_elm *elm2)
{
  void	*tmp;

  tmp = elm1->data;
  elm1->data = elm2->data;
  elm2->data = tmp;
}

int	sort_list(t_list *list, int abc, int (*cmp)())
{
  t_elm	*elm1;
  t_elm	*elm2;
  int	res;

  if (list == NULL || cmp == NULL)
    return (1);
  if (list->nb_elm < 2)
    return (0);
  elm1 = list->first;
  while (elm1->next != list->first)
  {
    elm2 = elm1->next;
    while (elm2 != list->first)
    {
      res = cmp(elm1->data, elm2->data);
      if (res > 0 && abc != 0)
	__swap_elm(elm1, elm2);
      else if (res < 0 && abc == 0)
	__swap_elm(elm1, elm2);
      elm2 = elm2->next;
    }
    elm1 = elm1->next;
  }
  return (0);
}

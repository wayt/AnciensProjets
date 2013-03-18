/*
** my_apply_on_list.c for ex_04 in /home/fest/Epitech/Jour_12/ex_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 23 19:35:10 2012 maxime ginters
** Last update Tue Oct 23 19:37:04 2012 maxime ginters
*/

int	my_apply_on_list(t_list *begin, int (*f)(void*))
{
  t_list	*list_ptr;

  list_ptr = begin;
  while (list_ptr != MY_NULL)
  {
    (*f)(list_ptr->data);
    list_ptr = list_ptr->next;
  }
  return (0);
}

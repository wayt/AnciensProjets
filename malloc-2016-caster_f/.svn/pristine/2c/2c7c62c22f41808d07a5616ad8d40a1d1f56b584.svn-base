/*
** free.c for  in /home/vaga/Projects/tek2/malloc
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sat Feb 09 16:04:13 2013 fabien casters
** Last update Sat Feb 09 17:08:08 2013 fabien casters
*/

#include "malloc.h"

pthread_mutex_t	__access = PTHREAD_MUTEX_INITIALIZER;

void		remove_from_mlc(malloc_t *ptr)
{
  malloc_t	*tmp;

  if (ptr == mlc)
    mlc = NULL;
  tmp = mlc;
  while (tmp)
  {
    if (tmp->next && tmp->next == ptr)
    {
      tmp->next = NULL;
      return ;
    }
    tmp = tmp->next;
  }
}

int		_safe_free(malloc_t *ptr)
{
  if (!ptr)
    return (0);
  if (ptr->next)
    return _safe_free(ptr->next);
  else if (ptr->used == 0)
  {
    remove_from_mlc(ptr);
    brk(ptr);
    return (1);
  }
  return (0);
}

void		free(void *ptr)
{
  if (!ptr)
    return ;
  ((malloc_t *)(ptr - T_SIZE))->used = 0;
  LOCK;
  while (_safe_free(mlc) == 1);
  UNLOCK;
}

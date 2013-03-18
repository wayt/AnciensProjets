/*
** malloc.c for Malloc in /home/fest/Epitech/malloc
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Feb 04 21:48:58 2013 maxime ginters
** Last update Sat Feb 09 17:06:00 2013 fabien casters
*/

#include "malloc.h"

size_t	get_size_to_alloc(size_t rew)
{
  size_t	i;
  static int	page = 0;

  if (page == 0)
    page = getpagesize();
  i = page;
  while (i < rew)
    i += page;
  return (i);
}

void		append_mlc(malloc_t* node)
{
  malloc_t	*tmp;

  if (!mlc)
    mlc = node;
  else
  {
    tmp = mlc;
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = node;
  }
}

void		*found_mlc_with_size(size_t size)
{
  malloc_t	*ptr;

  ptr = mlc;
  while (ptr)
  {
    if (ptr->size >= size && ptr->used == 0)
    {

      return (ptr);
    }
    ptr = ptr->next;
  }
  return (NULL);
}

void		*malloc(size_t taille)
{
  void		*addr;
  malloc_t	*node;
  size_t	alloc_size;

  if (taille == 0)
    return (NULL);
  LOCK;
  alloc_size = get_size_to_alloc(T_SIZE + taille);
  if ((addr = found_mlc_with_size(T_SIZE + taille)))
    ((malloc_t *)addr)->used = 1;
  else
  {
    addr = sbrk(alloc_size);
    node = addr;
    node->size = alloc_size;
    node->next = NULL;
    node->used = 1;
    append_mlc(node);
  }
  UNLOCK;
  return (addr + T_SIZE);
}

void		*realloc(void *ptr, size_t taille)
{
  void		*new;
  size_t	alloc_size;

  if (taille == 0)
  {
    free(ptr);
    return (NULL);
  }
  alloc_size = get_size_to_alloc(T_SIZE + taille);
  if (ptr && ((malloc_t *)(ptr - T_SIZE))->size >= alloc_size)
    return ptr;
  new = malloc(taille);
  if (ptr)
  {
    memcpy(new, ptr, MIN(((malloc_t *)(ptr - T_SIZE))->size - T_SIZE, taille));
    free(ptr);
  }
  return (new);
}


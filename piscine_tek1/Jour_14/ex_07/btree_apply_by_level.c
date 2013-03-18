/*
** btree_apply_by_level.c for Jour_14 in /home/fest/Epitech/Jour_14
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 11:32:00 2012 maxime ginters
** Last update Thu Oct 25 14:26:24 2012 maxime ginters
*/

#include <stdlib.h>

#ifndef NULL
  #define NULL 0x0
#endif

typedef struct s_btree
{
  struct s_btree	*left;
  struct s_btree	*right;
  void	*item;
} t_btree;

typedef struct s_queue
{
  struct s_queue	*next;
  t_btree	*item;
  int	level;
  int	first;
} t_queue;

void	queue_add(t_queue *qu, void *item, int level, int first)
{
  t_queue	*ptr;

  ptr = qu;
  if (ptr != NULL)
  {
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = malloc(sizeof(t_queue));
    ptr->next->next = NULL;
    ptr->next->item = item;
    ptr->next->level = level;
    ptr->next->first = first;
  }
  else
  {
    ptr = malloc(sizeof(t_queue));
    ptr->next = NULL;
    ptr->item = item;
    ptr->level = level;
    ptr->first = first;
  }
}

t_queue	*queue_extract(t_queue *qu)
{
  t_queue	*item;

  item = qu;
  qu = qu->next;
  return (item);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
  t_queue	*queue;
  t_queue	*curr;
  int	first;

  queue_add(queue, root, 0, 1);
  curr = NULL;
  while (queue != NULL)
  {
    curr = queue_extract(queue);
    (*applyf)(curr->item->item, curr->level, curr->first);
    first = 1;
    if (curr->item->left != NULL)
      queue_add(queue, curr->item->left, curr->level + 1, first--);
    if (curr->item->right != NULL)
      queue_add(queue, curr->item->right, curr->level + 1, first);
    free(curr);
  }
}

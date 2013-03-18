/*
** btree_insert_data.c for ex_04 in /home/fest/Epitech/Jour_14/ex_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 10:09:34 2012 maxime ginters
** Last update Thu Oct 25 14:28:58 2012 maxime ginters
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

t_btree	*btree_create_node(void *item)
{
  t_btree	*new;

  new = malloc(sizeof(t_btree));
  new->left = NULL;
  new->right = NULL;
  new->item = item;
  return (new);
}

void	btree_insert_data(t_btree **r, void *it, int (*cmpf)(void *, void *))
{
  t_btree	*node;

  node = (*r)->right;
  if ((*cmpf)((*r)->item, it) < 0)
    node = (*r)->left;

  if (node != NULL)
     btree_insert_data(&node, it, cmpf);
  else
    node = btree_create_node(it);
}

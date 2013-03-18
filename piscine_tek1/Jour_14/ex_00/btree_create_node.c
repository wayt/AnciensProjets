/*
** btree_create_node.c for ex_00 in /home/fest/Epitech/Jour_14/ex_00
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 09:45:44 2012 maxime ginters
** Last update Thu Oct 25 14:30:42 2012 maxime ginters
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

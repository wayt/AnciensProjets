/*
** rb_insert.c for ex_08 in /home/fest/Epitech/Jour_14/ex_08
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 13:08:40 2012 maxime ginters
** Last update Thu Oct 25 14:21:00 2012 maxime ginters
*/

#include <stdlib.h>

#ifndef NULL
  #define NULL 0x0
#endif

typedef struct rb_node
{
  struct rb_node	*left;
  struct rb_node	*right;
  void	*data;
  enum RB_COLOR { RB_BLACK, RB_RED }	color;
  int	is_root;
} t_rb_node;

t_rb_node	*create_node(void *data, enum RB_COLOR color)
{
  t_rb_node	*new;

  new = malloc(sizeof(*new));
  new->left = NULL;
  new->right = NULL;
  new->data = data;
  new->color = color;
  new->is_root = 0;
  return (new);
}

void	rb_insert(t_rb_node **r, void *data, int (*cmpf)(void *, void *))
{
  enum RB_COLOR color;

  if (*r == NULL)
  {
    *r = create_node(data, RB_BLACK);
    (*r)->is_root = 1;
    return ;
  }
  color = ((*r)->color == RB_BLACK && (*r)->is_root == 0 ? RB_RED : RB_BLACK);
  if ((*cmpf)((*r)->data, data) < 0)
  {
    if ((*r)->left  == NULL)
      (*r)->left = create_node(data, color);
    else
      rb_insert(&(*r)->left, data, cmpf);
  }
  else
  {
    if ((*r)->right == NULL)
      (*r)->right = create_node(data, color);
    else
      rb_insert(&(*r)->right, data, cmpf);
  }
}

/*
** btree_search_item.c for ex_05 in /home/fest/Epitech/Jour_14/ex_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 10:27:27 2012 maxime ginters
** Last update Thu Oct 25 13:07:51 2012 maxime ginters
*/

#ifndef NULL
  #define NULL 0x0
#endif

typedef struct s_btree
{
  struct s_btree	*left;
  struct s_btree	*right;
  void	*item;
} t_btree;

void	*btree_search_item(t_btree *r, void *dt, int (*cmpf)(void *, void *))
{
  int	result;
  t_btree	*node;

  result = (*cmpf)(r->item, dt);
  if (result == 0)
    return (r->item);
  node = r->right;
  if (result < 0)
    node = r->left;
  if (node == NULL)
    return (NULL);
  else
    return (btree_search_item(node, dt, cmpf));

}

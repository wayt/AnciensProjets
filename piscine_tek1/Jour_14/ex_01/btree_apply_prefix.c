/*
** btree_apply_prefix.c for ex_01 in /home/fest/Epitech/Jour_14/ex_01
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 09:54:58 2012 maxime ginters
** Last update Thu Oct 25 10:08:06 2012 maxime ginters
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

void	btree_apply_prefix(t_btree *root, int (*applyf)(void *))
{
  (*applyf)(root->item);
  if (root->left != NULL)
    btree_apply_prefix(root->left, applyf);
  if (root->right != NULL)
    btree_apply_prefix(root->right, applyf);
}

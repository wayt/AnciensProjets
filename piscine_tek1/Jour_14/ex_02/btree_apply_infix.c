/*
** btree_apply_infix.c for ex_02 in /home/fest/Epitech/Jour_14/ex_02
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 10:00:16 2012 maxime ginters
** Last update Thu Oct 25 14:29:44 2012 maxime ginters
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

void	btree_apply_infix(t_btree *root, int (*applyf)(void *))
{
  if (root->left != NULL)
    btree_apply_infix(root->left, applyf);
  (*applyf)(root->item);
  if (root->right != NULL)
    btree_apply_infix(root->right, applyf);
}

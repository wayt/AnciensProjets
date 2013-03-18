/*
** btree_apply_suffix.c for ex_03 in /home/fest/Epitech/Jour_14/ex_03
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 10:04:44 2012 maxime ginters
** Last update Thu Oct 25 10:07:43 2012 maxime ginters
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

void	btree_apply_suffix(t_btree *root, int (*applyf)(void *))
{
  if (root->left != NULL)
    btree_apply_suffix(root->left, applyf);
  if (root->right != NULL)
    btree_apply_suffix(root->right, applyf);
  (*applyf)(root->item);
}

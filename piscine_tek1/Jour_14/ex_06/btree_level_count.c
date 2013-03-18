/*
** btree_level_count.c for ex_06 in /home/fest/Epitech/Jour_14/ex_06
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 11:07:18 2012 maxime ginters
** Last update Thu Oct 25 11:30:27 2012 maxime ginters
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

int	b_max(int a, int b)
{
  return (a > b ? a : b);
}

int	btree_level_count(t_btree *r)
{
  int	max;
  if (r == NULL)
    return (0);
  else
  {
     max = b_max(btree_level_count(r->left), btree_level_count(r->right));
    return (1 + max);
  }
}

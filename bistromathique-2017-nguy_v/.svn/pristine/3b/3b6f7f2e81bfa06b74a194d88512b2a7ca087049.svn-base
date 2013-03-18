/*
** calc_utils.c for bistromathique in /home/fest/Epitech/bistromathique
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Nov 06 13:32:20 2012 maxime ginters
** Last update Tue Nov 06 14:59:12 2012 maxime ginters
*/

#include "my.h"
#include "bistromathique.h"

int	get_operator_pos(char *expr, char ops[7], int pos, int pre_op)
{
  int	i;

  if (pre_op == 1)
  {
    i = pos - 1;
    while (i > 0 && is_operator(expr[i], ops, 0) == 0)
      --i;
    if (expr[i] == ops[OP_SUB_IDX] && i > 0 &&
      is_operator(expr[i - 1], ops, 0) == 1)
      --i;
    return (i);
  }
  i = pos + 1;
  if (expr[i] == ops[OP_SUB_IDX] && i != 1)
    ++i;
  while (expr[i] != '\0' && is_operator(expr[i], ops, 0) == 0)
    ++i;
  return (i);
}

int	is_operator(char c, char ops[7], int impo)
{
  if (impo == 1)
  {
    if (c == ops[OP_MULT_IDX] || c == ops[OP_DIV_IDX] || c == ops[OP_MOD_IDX])
      return (1);
    return (0);
  }
  if (impo == -1)
  {
    if (c == ops[OP_PLUS_IDX] || c == ops[OP_SUB_IDX])
      return (1);
    return (0);
  }
  if (c == ops[OP_MULT_IDX] || c == ops[OP_DIV_IDX] || c == ops[OP_MOD_IDX]
	|| c == ops[OP_PLUS_IDX] || c == ops[OP_SUB_IDX])
    return (1);
  return (0);
}

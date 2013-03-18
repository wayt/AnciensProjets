/*
** do_op.c for do-op in /home/fest/Epitech/Jour_11/do-op
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 22 20:50:40 2012 maxime ginters
** Last update Fri Oct 26 15:44:21 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

char	*do_op_add(int a, int b)
{
  return (int_to_str(a + b));
}

char	*do_op_min(int a, int b)
{
  return (int_to_str(a - b));
}

char	*do_op_mult(int a, int b)
{
  return (int_to_str(a * b));
}

char	*do_op_div(int a, int b)
{
  if (b == 0)
    return (int_to_str(0));
  return (int_to_str(a / b));
}

char	*do_op_mod(int a, int b)
{
  if (b == 0)
    return (int_to_str(0));
  return (int_to_str(a % b));
}

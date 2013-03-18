/*
** eval_expr.c for eval_expr in /home/fest/Epitech/eval_expr
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 16:40:27 2012 maxime ginters
** Last update Sat Nov 10 17:23:37 2012 maxime ginters
*/

#include <stdlib.h>
#include "eval_expr.h"
#include "my.h"

int	eval_expr(char *str)
{
  char	*work_str;
  int	value;

  work_str = trim_space(str);
  work_str = do_most_prior(work_str);
  value = my_getnbr(work_str);
  free(work_str);
  return (value);
}

char	*do_most_prior(char *str)
{
  char	*current;
  int	start;
  int	end;

  if (my_str_isnum(str) == 1)
    return (str);
  current = get_parenthese_expr(str, &start, &end);
  if (current != NULL)
  {
    current = trim_parentheses(current);
    current = calc(current);
    current = str_replace(str, start, end, current);
    return (do_most_prior(current));
  }
  else
  {
    current = trim_parentheses(str);
    return (calc(current));
  }
}

char	*calc(char *str)
{
  int	op_pos;
  int	st;
  int	end;
  int	tab[2];
  char	*s;

  printf("calc : %s\n", str);
  if (my_str_isnum(str) == 1)
    return (str);
  op_pos = get_operator_pos(str, 0, 0);
  st = get_operator_pos(str, op_pos, 0);
  if (op_pos + 1 != st && is_operator(str[op_pos], -1) == 1 &&
    is_operator(str[st], 1) == 1)
    op_pos = st;
  st = get_operator_pos(str, op_pos, 1);
  st += (st == 0 ? 0 : 1);
  s = get_sub_str(str, st, op_pos - 1);
  tab[0] = my_getnbr(s);
  free(s);
  end = get_operator_pos(str, op_pos, 0);
  end -= 1;
  s = get_sub_str(str, op_pos + 1, end);
  tab[1] = my_getnbr(s);
  free(s);
  s = str_replace(str, st, end, calc_int_to_str(tab[0], tab[1], str[op_pos]));
  printf("expr : %s\n", s);
  return (calc(s));
}

char	*calc_int_to_str(int a, int b, char c)
{
  if (c == '+')
    return (do_op_add(a, b));
  else if (c == '-')
    return (do_op_min(a, b));
  else if (c == '*')
    return (do_op_mult(a, b));
  else if (c == '/')
    return (do_op_div(a, b));
  else if (c == '%')
    return (do_op_mod(a, b));
  return (my_strdup("0"));
}

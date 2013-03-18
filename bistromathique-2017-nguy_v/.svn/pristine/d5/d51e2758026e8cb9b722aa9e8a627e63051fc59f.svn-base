/*
** get_functions.c for eval_expr in /home/fest/Epitech/eval_expr
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 26 17:44:20 2012 maxime ginters
** Last update Fri Oct 26 18:09:56 2012 maxime ginters
*/

#include "eval_expr.h"
#include "my.h"

int	get_operator_pos(char *str, int pos, int pre_op)
{
  int	i;

  if (pre_op == 1)
  {
    i = pos - 1;
    while (i > 0 && is_operator(str[i], 0) == 0)
      --i;
    if (str[i] == '-' && i > 0 && is_operator(str[i - 1], 0) == 1)
      --i;
    return (i);
  }
  else
  {
    i = pos + 1;
    if (str[i] == '-' && i != 1)
      ++i;
    while (str[i] != '\0' && is_operator(str[i], 0) == 0)
      ++i;
    return (i);
  }
}

int	is_operator(char c, int important)
{
  if (important == 1)
  {
    if (c == '*' || c == '/' || c == '%')
      return (1);
    else
      return (0);
  }
  if (important == -1)
  {
    if (c == '-' || c == '+')
      return (1);
    else
      return (0);
  }
  if (c == '-' || c == '+' || c == '*' || c == '/' || c == '%')
    return (1);
  return (0);
}

char	*get_parenthese_expr(char *str, int *st, int *e)
{
  int	i;
  int	start;
  int	end;

  i = 0;
  start = -1;
  end = -1;
  while (str[i] != '\0' && end == -1)
  {
    if (str[i] == '(')
      start = i;
    else if (start != -1 && str[i] == ')')
      end = i;
    ++i;
  }
  if (end < 0 || start < 0)
    return (NULL);
  *st = start;
  *e = end;
  return (get_sub_str(str, start, end));
}

int	get_size_for_char(int v)
{
  int	size;

  size = 1;
  while (v / my_power_it(10, size) > 0)
    ++size;
  size = (v <= 9 ? 1 : size + 1);
  return (size);
}

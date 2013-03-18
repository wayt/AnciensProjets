/*
** str_utils.c for bistromathique in /home/fest/Epitech/bistromathique
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Nov 06 11:27:47 2012 maxime ginters
** Last update Wed Nov 07 14:46:37 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

int	expr_is_full_num(char *expr, t_base *base, char ops[7])
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (expr[0] == ops[OP_SUB_IDX])
    ++i;
  while (expr[i] != '\0')
  {
    j = 0;
    while (j < base->length && expr[i] != base->str[j])
      ++j;
    if (j == base->length)
      return (0);
    ++i;
  }
  return (1);
}

char	*get_parentheses_expr(char *expr, int *st, int *e,
	char ops[7])
{
  int	i;
  int	start;
  int	end;

  i = 0;
  start = -1;
  end = -1;
  while (expr[i] != '\0' && end == -1)
  {
    if (expr[i] == ops[OP_OPEN_PARENT_IDX])
      start = i;
    else if (start != -1 && expr[i] == ops[OP_CLOSE_PARENT_IDX])
      end = i;
    ++i;
  }
  if (end < 0 || start < 0)
    return (NULL);
  *st = start;
  *e = end;
  return (get_sub_str(expr, start, end));
}

char	*get_sub_str(char *str, int start, int end)
{
  char	*new;
  int	i;

  new = malloc(((end - start + 1) + 1) * sizeof(char));
  check_malloc(new);
  my_memset(new, 0x0, (end - start + 1) + 1);
  i = 0;
  while (start <= end)
    new[i++] = str[start++];
  return (new);
}

char	*trim_parentheses(char *str, char ops[7])
{
  int	len;
  char	*new;
  int	i;

  len = my_strlen(str);
  new = NULL;
  if (str[0] == ops[OP_OPEN_PARENT_IDX] &&
    str[len - 1] == ops[OP_CLOSE_PARENT_IDX])
  {
    new = malloc((len - 2 + 1) * sizeof(char));
    check_malloc(new);
    my_memset(new, 0x0, len - 2 + 1);
    i = 1;
    while (str[i] != ops[OP_CLOSE_PARENT_IDX])
      new[i - 1] = str[i++];
    free(str);
    return (new);
  }
  return (str);
}

char	*str_replace(char *s, int st, int e, char *by)
{
  char	*new;
  int	i;
  int	j;
  int	size;

  size = my_strlen(s) - (e - st + 1) + my_strlen(by) + 1;
  new = malloc(size * sizeof(char));
  check_malloc(new);
  my_memset(new, 0x0, size);
  i = 0;
  while (i < st)
    new[i] = s[i++];
  j = 0;
  while (by[j] != '\0')
    new[i++] = by[j++];
  j = e + 1;
  while (s[j] != '\0')
    new[i++] = s[j++];
  free(s);
  free(by);
  return (new);
}

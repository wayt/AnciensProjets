/*
** str_functions.c for eval_expr in /home/fest/Epitech/eval_expr
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 26 17:34:13 2012 maxime ginters
** Last update Fri Oct 26 18:46:38 2012 maxime ginters
*/

#include <stdlib.h>
#include "eval_expr.h"
#include "my.h"

char	*int_to_str(int v)
{
  int	size;
  char	*str;
  int	neg;

  if (v == 0)
    return (my_strdup("0"));
  neg = 1;
  if (v < 0)
    neg = -1;
  v *= neg;
  size = get_size_for_char(v);
  str = malloc((size + (neg == -1 ? 2 : 1)) * sizeof(char));
  size = 0;
  while (v > 0)
  {
    str[size] = ('0' + (v % 10));
    ++size;
    v /= 10;
  }
  if (neg == -1)
    str[size++] = '-';
  str[size] = '\0';
  return (my_revstr(str));
}

char	*trim_space(char *str)
{
  int	size;
  int	i;
  int	j;
  char	*new;

  i = 0;
  size = 0;
  while (str[i] != '\0')
    if (str[i++] != ' ')
      ++size;
  new = malloc((size + 1) * sizeof(char));
  my_memset(new, 0x0, size + 1);
  i = 0;
  j = 0;
  while (str[i] != '\0')
  {
    if (str[i] != ' ')
      new[j++] = str[i];
    ++i;
  }
  new[j] = '\0';
  return (new);
}

char	*trim_parentheses(char *str)
{
  int	len;
  char	*new;
  int	i;

  len = my_strlen(str);
  new = NULL;
  if (str[0] == '(' && str[len - 1] == ')')
  {
    new = malloc((len - 2 + 1) * sizeof(char));
    my_memset(new, 0x0, len - 2 + 1);
    i = 1;
    while (str[i] != ')')
      new[i - 1] = str[i++];
    new[i - 1] = '\0';
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
  new[i] = '\0';
  free(s);
  free(by);
  return (new);
}

char	*get_sub_str(char *str, int start, int end)
{
  char	*new;
  int	i;

  new = malloc(((end - start + 1) + 1) * sizeof(char));
  my_memset(new, 0x0, (end - start + 1) + 1);
  i = 0;
  while (start <= end)
  {
    new[i] = str[start];
    ++i;
    ++start;
  }
  return (new);
}


/*
** op_div.c for operations in /home/fest/Epitech/bistromathique-2017-nguy_v/operations
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sun Nov 11 15:34:12 2012 maxime ginters
** Last update Sun Nov 11 17:05:30 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"
#include "operations.h"

char	*absolute(char *str, char ops[7])
{
  char	*value;
  if (str[0] != ops[OP_SUB_IDX])
    return (str);
  value = my_strdup(str + 1);
  free(str);
  return (value);
}

int	is_null(char *str, t_base *base)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] != base->str[0])
      return (0);
    ++i;
  }
  return (1);
}

char	*clean_zero(char *str, t_base *base, char ops[7])
{
  int	i;
  char *buff;
  int	buff_i;
  int	find;

  buff = xmalloc((my_strlen(str) + 1) * sizeof(char));
  my_memset(buff, 0x0, my_strlen(str) + 1);
  i = 0;
  buff_i = 0;
  find = 0;
  while (str[i] != '\0')
  {
    if (i == 0 && str[i] == ops[OP_SUB_IDX])
      buff[buff_i++] = str[i];
    else if (str[i] != base->str[0] || find == 1)
    {
      buff[buff_i++] = str[i];
      find = 1;
    }
    ++i;
  }
  if (find == 0)
    buff[buff_i++] = base->str[0];
  free(str);
  return (buff);
}

char	**compute_tab(char *s1, char *s2)
{
  char	**tab;

  tab = xmalloc(2 * sizeof(char*));
  tab[0] = s1;
  tab[1] = s2;
  return (tab);
}

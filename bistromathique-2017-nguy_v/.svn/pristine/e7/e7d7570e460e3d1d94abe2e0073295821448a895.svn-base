/*
** op_add.c for operations in /home/fest/Epitech/bistromathique-2017-nguy_v/operations
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sun Nov 11 17:19:34 2012 maxime ginters
** Last update Sun Nov 11 18:34:53 2012 maxime ginters
*/

#include "my.h"
#include "operations.h"

int	get_op_add_ret(int len[2], char *tab[2], t_base *base, char ops[7])
{
  if (len[0] >= min_ref(tab[0], ops) && len[1] >= min_ref(tab[1], ops))
    return (base->value[tab[0][len[0]]] + base->value[tab[1][len[1]]]);
  else if (len[0] >= min_ref(tab[0], ops))
    return (base->value[tab[0][len[0]]]);
  else if (len[1] >= min_ref(tab[1], ops))
    return (base->value[tab[1][len[1]]]);
  return (0);
}

char	*op_add(char *tab[2], t_base *base, char ops[7], int len[2])
{
  int	i;
  char	*buff;
  int	ret;

  buff = xmalloc((MAX(len[0], len[1]) + 3) * sizeof(char));
  my_memset(buff, 0x0, MAX(len[0], len[1]) + 3);
  i = 0;
  ret = 0;
  while (len[0] >= min_ref(tab[0], ops) || len[1] >= min_ref(tab[1], ops))
  {
    ret += get_op_add_ret(len, tab, base, ops);
    buff[i++] = get_char_for_value(ret % base->length, base);
    ret /= base->length;
    --len[0];
    --len[1];
  }
  if (ret > 0)
    buff[i++] = get_char_for_value(ret % base->length, base);
  if (min_ref(tab[0], ops) == 1 && min_ref(tab[1], ops) == 1)
    buff[i++] = '-';
  return (my_revstr(my_strdup(buff)));
}

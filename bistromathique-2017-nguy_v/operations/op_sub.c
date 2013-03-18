/*
** op_sub.c for operations in /home/fest/Epitech/bistromathique/operations
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 13:58:07 2012 maxime ginters
** Last update Sun Nov 11 20:27:48 2012 maxime ginters
*/

#include "my.h"
#include "operations.h"
#include "bistromathique.h"

void	switch_tab(char *str1, char *str2)
{
  char	*dassault;

  dassault = str1;
  str1 = str2;
  str1 = dassault;
}

void	init_var(int *i, int *ret, int *tmp)
{
  *i = 0;
  *ret = 0;
  *tmp = 0;
}

char	*_op_sub(char *tab[2], t_base *base, char ops[7], int len[2])
{
  char	*buff;
  int	i;
  int	ret;
  int	tmp;

  buff = xmalloc((MAX(len[0], len[1]) + 3) * sizeof(char));
  my_memset(buff, 0x0, MAX(len[0], len[1]) + 3);
  init_var(&i, &ret, &tmp);
  while (len[0] >= min_ref(tab[0], ops) || len[1] >= min_ref(tab[1], ops))
  {
    if (len[0] >= min_ref(tab[0], ops) && len[1] >= min_ref(tab[1], ops))
      tmp = base->value[tab[0][len[0]]] - base->value[tab[1][len[1]]] - ret;
    else if (len[0] >= min_ref(tab[0], ops))
      tmp = base->value[tab[0][len[0]]] - ret;
    ret = (tmp < 0);
    if (tmp < 0)
      tmp += base->length;
    buff[i++] = get_char_for_value(tmp % base->length, base);
    --len[0];
    --len[1];
  }
  if (ret > 0)
    buff[i++] = get_char_for_value(ret % base->length, base);
  return (my_revstr(my_strdup(buff)));
}

char	*op_sub(char *tab[2], t_base *base, char ops[7], int neg[2])
{
  int	a_high;
  char	*buff;
  int	len[2];

  a_high = a_is_high_b(tab[0], tab[1], base, ops);
  if (a_high == 0)
    switch_tab(tab[0], tab[1]);
  len[0] = my_strlen(tab[0]) - 1;
  len[1] = my_strlen(tab[1]) - 1;

  buff = _op_sub(tab, base, ops, len);
  if ((a_high == 1 && neg[0] == 1) || (a_high == 0 && neg[1] == 1) ||
    (a_high == 0 && neg[0] == 0 && neg[1] == 0))
      return (my_strcat(my_strdup("-"), buff));
  return (buff);
}

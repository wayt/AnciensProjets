/*
** operations.c for temp_operations in /home/fest/Epitech/bistromathique/temp_operations
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Nov 06 16:23:06 2012 maxime ginters
** Last update Sun Nov 11 18:51:44 2012 maxime ginters
*/

#include <assert.h>
#include <stdlib.h>
#include "my.h"
#include "operations.h"
#include "bistromathique.h"

#define rm_op remove_operator_from_second_str
#define c_t compute_tab
#define dup my_strdup

char	*do_op_add(char *tab[2], t_base *base, char ops[7])
{
  int	len[2];

  if (tab[0][0] == ops[OP_SUB_IDX] && tab[1][0] != ops[OP_SUB_IDX])
    return (do_op_sub(rm_op(swap_tab(tab), ops, 1), base, ops));
  if (tab[1][0] == ops[OP_SUB_IDX] && tab[0][0] != ops[OP_SUB_IDX])
    return (do_op_sub(rm_op(tab, ops, 1), base, ops));
  len[0] = my_strlen(tab[0]) - 1;
  len[1] = my_strlen(tab[1]) - 1;
  return (op_add(tab, base, ops, len));
}

char	*do_op_sub(char *tab[2], t_base *base, char ops[7])
{
  int	neg[2];

  if (tab[0][0] == ops[OP_SUB_IDX] && tab[1][0] != ops[OP_SUB_IDX])
    return (my_strcat(dup("-"), do_op_add(rm_op(tab, ops, 0), base, ops)));
  else if (tab[1][0] == ops[OP_SUB_IDX])
    return (do_op_add(rm_op(tab, ops, 1), base, ops));
  neg[0] = (tab[0][0] == ops[OP_SUB_IDX]);
  neg[1] = (tab[1][0] == ops[OP_SUB_IDX]);
  return (op_sub(tab, base, ops, neg));
}

char	*do_op_mult(char *tab[2], t_base *base, char ops[7])
{
  int	var[6];

  var[0] = 0;
  var[1] = 0;
  var[2] = 0;
  var[3] = 0;
  var[4] = my_strlen(tab[0]) - 1;
  var[5] = my_strlen(tab[1]) - 1;
  if (min_ref(tab[0], ops) != min_ref(tab[1], ops))
    return (my_strcat(dup("-"), op_mult(tab, base, ops, var)));
  return (op_mult(tab, base, ops, var));
}

char	*do_op_div(char *tab[2], t_base *base, char ops[7])
{
  int	len[2];
  char	*buff;
  char	*divisor;
  int	neg[2];

  neg[0] = min_ref(tab[0], ops);
  neg[1] = min_ref(tab[1], ops);
  divisor = absolute(tab[1], ops);
  len[0] = my_strlen(tab[0]) - 1;
  len[1] = my_strlen(tab[1]) - 1;
  buff = xmalloc((MAX(len[0], len[1]) + 1) * sizeof(char));
  my_memset(buff, base->str[0], MAX(len[0], len[1]) + 1);
  buff = my_strcpy(buff, "0");
  tab[0] = absolute(tab[0], ops);
  tab[1] = dup(divisor);
  while (tab[0][0] != ops[OP_SUB_IDX] && is_null(tab[0], base) == 0)
  {
    tab[0] = clean_zero(do_op_sub(tab, base, ops), base, ops);
    tab[1] = dup(divisor);
    buff = do_op_add(c_t(dup(buff), dup("1")), base, ops);
  }
  if (neg[0] != neg[1])
    return (do_op_mult(c_t(dup(buff), dup("-1")), base, ops));
  return (dup(buff));
}

char	*do_op_mod(char *tab[2], t_base *base, char ops[7])
{
  int	len[2];
  char	*buff;
  char	*divisor;
  int	neg[2];

  neg[0] = min_ref(tab[0], ops);
  neg[1] = min_ref(tab[1], ops);

  divisor = absolute(tab[1], ops);
  tab[0] = absolute(tab[0], ops);
  tab[1] = dup(divisor);
  while (tab[0][0] != ops[OP_SUB_IDX] && is_null(tab[0], base) == 0)
  {
    tab[0] = clean_zero(do_op_sub(tab, base, ops), base, ops);
    tab[1] = dup(divisor);
  }
  return (absolute(tab[0], ops));
}

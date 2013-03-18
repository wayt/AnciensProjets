/*
** op_mult.c for operations in /home/fest/Epitech/bistromathique-2017-nguy_v/operations
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sun Nov 11 18:36:41 2012 maxime ginters
** Last update Sun Nov 11 18:52:08 2012 maxime ginters
*/

#include "my.h"
#include "operations.h"

char	*op_mult(char *tab[2], t_base *base, char ops[7], int var[6])
{
  char	*buff;

  buff = xmalloc((var[4] + var[5] + 3) * sizeof(char));
  my_memset(buff, gcfv(0, base), var[4] + var[5] + 2);
  while (var[5] >= min_ref(tab[1], ops))
  {
    var[4] = my_strlen(tab[0]) - 1;
    while (var[4] >= min_ref(tab[0], ops))
    {
      var[1] = base->value[tab[0][var[4]]] * base->value[tab[1][var[5]]];
      var[1] += base->value[buff[var[0]]];
      buff[var[0]] = gcfv(var[1] % base->length, base);
      var[2] = 1;
      while (var[1] / base->length > 0)
      {
        var[1] = (var[1] / base->length) + base->value[buff[var[0] + var[2]]];
        buff[var[0] + var[2]++] = gcfv(var[1] % base->length, base);
      }
      ++var[0];
      --var[4];
    }
    var[0] = ++var[3];
    --var[5];
  }
  return (my_revstr(my_strdup(buff)));
}

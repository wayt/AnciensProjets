/*
** get_value.c for asm in /home/caster_f/projects/corewar/src/asm
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Thu Dec 06 12:56:16 2012 fabien casters
** Last update Sat Dec 15 11:40:30 2012 vincent leroy
*/

#include "op.h"
#include "asm.h"

int	get_value(char *data, int line)
{
  int	nb;

  if (data[0] == DIRECT_CHAR)
    return (my_getnbr(data));
  else if (data[0] == 'r' && is_num(&data[1]))
  {
    nb = my_getnbr(&data[1]);
    if (nb > REG_NUMBER)
      line_error(REG_ERROR, line, 1);
    return (nb);
  }
  else if (is_num(data))
    return (my_getnbr(data));
}

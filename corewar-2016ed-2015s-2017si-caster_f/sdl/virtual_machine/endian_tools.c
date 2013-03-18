/*
** endian_tools.c for virtual_machine in /home/fest/Epitech/CoreWar/core/virtual_machine
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Dec 08 15:56:24 2012 maxime ginters
** Last update Sat Dec 08 16:23:01 2012 maxime ginters
*/

#include "virtual_machine.h"

int	is_big_endian()
{
  int	i = 1;
  char	*ptr = (char*)&i;
  return (*ptr == 1 ? 0 : 1);
}

int swap_int(int val )
{
  val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF );
  return (val << 16) | ((val >> 16) & 0xFFFF);
}

int	endian_cmp(int val, int ref)
{
  if (is_big_endian())
    return (val == ref);
  return (swap_int(val) == ref);
}


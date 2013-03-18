/*
** corewar.c for core in /home/fest/Epitech/CoreWar/core
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Dec 15 17:10:21 2012 maxime ginters
** Last update Sat Dec 15 20:34:46 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"

int	get_new_pid()
{
  static int	pid = 5;

  return (pid++);
}

int	is_valid_player(t_vm *vm, int nb)
{
  if (nb < 1 || nb > MAX_PLAYER)
    return (0);
  if (vm->register_player[nb] == 1)
    return (1);
  return (0);
}

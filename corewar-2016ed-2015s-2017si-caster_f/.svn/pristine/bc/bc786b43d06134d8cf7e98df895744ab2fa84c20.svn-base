/*
** cmd_aff.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:48:11 2012 maxime ginters
** Last update dim. déc. 16 18:04:08 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	handle_aff(t_vm *vm, t_program *prog, int index)
{
  int	id;
  char	chr;

  id = getnbr_wsize(vm->memory, avance_mem(prog->pc, 2), 1) - 1;
  if (id < 0 || id >= REG_NUMBER)
    return (print_segfault(prog, 0));
  chr = getnbr_wsize(prog->registre[id], 0, REG_SIZE) % 256;
  write(1, &chr, 1);
  (void)index;
  return (2 + 1);
}

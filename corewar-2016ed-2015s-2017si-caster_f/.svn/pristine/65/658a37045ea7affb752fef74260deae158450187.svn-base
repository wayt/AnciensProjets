/*
** cmd_zjmp.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:42:44 2012 maxime ginters
** Last update dim. déc. 16 17:46:33 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	recule_mem(int pc, int val)
{
  while (val > 0)
  {
    if (--pc < 0)
      pc = MEM_SIZE - 1;
    --val;
  }
  return (pc);
}

int	handle_zjmp(t_vm *vm, t_program *prog, int index)
{
  short	id;

  if (prog->carry == 0)
    return (1 + IND_SIZE);
  id = (short)getnbr_wsize(vm->memory, avance_mem(prog->pc, 1), IND_SIZE);
  if (id < 0)
    prog->pc = recule_mem(prog->pc, (id % IDX_MOD));
  else
    prog->pc = avance_mem(prog->pc, (id % IDX_MOD));
  (void)index;
  return (0);
}

/*
** cmd_aff.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:48:11 2012 maxime ginters
** Last update Thu Dec 13 17:14:32 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	handle_aff(t_vm *vm, t_program *prog, int index)
{
  int	id;
  int	chr;

  id = getnbr_wsize(vm->memory, avance_mem(prog->pc, 2), 1) - 1;
  if (id < 0 || id >= REG_NUMBER)
  {
    my_printf("%s : try to access to an invalide register %d\n",
        prog->header->prog_name, id);
    prog->active = 0;
    return (0);
  }
  chr = getnbr_wsize(prog->registre[id], 0, REG_SIZE);
  my_printf("%c", (char)(chr % 256));
  (void)index;
  return (2 + 1);
}

/*
** cmd_live.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:33:32 2012 maxime ginters
** Last update Sat Dec 15 20:35:54 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"
#include "my.h"

int	handle_live(t_vm *vm, t_program *prog, int index)
{
  int	id;

  id = get_prog_number(prog, vm);
  if (id < 0)
    return (0);
  if (++vm->nb_live == NBR_LIVE)
  {
    vm->nb_live = 0;
    vm->cycle_to_die -= CYCLE_DELTA;
    my_printf("[VM] - cycle to die : %d\n", vm->cycle_to_die);
  }
  if (vm->progs_live[id] == -1)
  {
    prog->active = 0;
    return (0);
  }
  vm->progs_live[id] = vm->cycle;
  my_printf("le joueur %d (%s) est en vie\n", id,
      get_prog_name(vm, id));
  (void)index;
  return (5);
}

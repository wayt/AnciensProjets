/*
** cmd_lfork.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:47:30 2012 maxime ginters
** Last update Sat Dec 15 20:36:26 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	get_lfork_sleep_time()
{
  int	i;

  i = 0;
  while (corewar_commands[i].cmd)
  {
    if (corewar_commands[i].cmd == 0x0f)
      return (corewar_commands[i].sleep);
    ++i;
  }
  return (0);
}

int	handle_lfork(t_vm *vm, t_program *prog, int index)
{
  int	id;
  t_program	*new;

  id = getnbr_wsize(vm->memory, avance_mem(prog->pc, 1), T_DIR);
  if ((new = malloc(sizeof(t_program))) == 0)
  {
    my_printf("Error: program %d fail to fork\n", get_prog_number(prog, vm));
    return (2 + T_IND);
  }
  prog->carry = id == 0 ? 1 : 0;
  my_memcpy(new, prog, sizeof(t_program));
  add_last_elm(vm->prog_list, new);
  new->sleep = get_fork_sleep_time() + 1;
  new->pc = avance_mem(prog->pc, id);
  new->pid = get_new_pid();
  (void)index;
  return (2 + T_DIR);
}

/*
** vm_run.c for virtual_machine in /home/fest/Epitech/CoreWar/core/virtual_machine
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 15:17:44 2012 maxime ginters
** Last update Fri Mar 08 21:07:37 2013 maxime ginters
*/

#include <unistd.h>
#include "my.h"
#include "virtual_machine.h"
#include "commands.h"

int	get_cmd_index(char cmd)
{
  int	i;

  i = 0;
  while (corewar_commands[i].cmd)
  {
    if (corewar_commands[i].cmd == cmd)
      return (i);
    ++i;
  }
  return (-1);
}

int	exec_prog(t_vm	*vm, t_program *curr, int idx)
{
  int	i;

  if (curr->active == 0 || curr->sleep-- > 0)
    return (0);
  i = get_cmd_index(vm->memory[curr->pc]);
  if (i >= 0)
  {
      if (vm->param->debug == 1)
        my_printf("player [%d] prog [%s] call : %s (pc : %d)\n",
            get_prog_number(curr, vm),
        curr->header->prog_name,  corewar_commands[i].name, curr->pc);
    curr->pc = avance_mem(curr->pc,
        (corewar_commands[i].funct)(vm, curr, idx));
    curr->sleep = corewar_commands[i].sleep;
  }
  else if (++curr->pc >= MEM_SIZE)
    curr->pc -= MEM_SIZE;
  return (0);
}

int	check_end_cond(t_vm *vm)
{
  int	i;
  t_program	*curr;

  i = get_active_prog_count(vm);
  if (i == 1)
  {
    curr = get_last_active_prog(vm);
    if (curr == NULL)
      my_printf("Error: aucun vainceur\n");
    else
      my_printf("Le joueur %d (%s) a gagne\n", curr->registre[0][REG_SIZE - 1],
          get_prog_name(vm, (int)curr->registre[0][REG_SIZE - 1]));
    return (0);
  }
  else if (i <= 0)
    return (0);
  return (1);
}

int	boucle_prog(t_vm *vm, int i)
{
  t_program	*curr;
  int	id;

  curr = get_data(vm->prog_list, i);
  if (curr->active == 1)
  {
    id = get_prog_number(curr, vm);
    if (id >= 0 && vm->progs_live[id] != -1)
    {
      if (vm->cycle - vm->progs_live[id] > vm->cycle_to_die)
      {
        my_printf("Player %d : timed out ... \n", id);
        curr->active = 0;
        vm->progs_live[id] = -1;
      }
      exec_prog(vm, curr, i);
    }
  }
  return (check_end_cond(vm));
}

int	vm_run(t_vm	*vm)
{
  int	i;
  char	run;

  run = 1;
  while (run == 1)
  {
    i = 0;
    while (i < vm->prog_list->nb_elm && run == 1)
      run = boucle_prog(vm, i++);
    if (run == 1 && vm->param->debug == 1)
      my_printf("Cycle : %d\n", vm->cycle);
    if (++vm->cycle == vm->param->nbr_cycle)
    {
      dump_memory(vm->memory);
      return (0);
    }
  }
  return (0);
}

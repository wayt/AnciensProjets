/*
** vm_tools.c for virtual_machine in /home/fest/Epitech/CoreWar/core/virtual_machine
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Dec 11 20:41:42 2012 maxime ginters
** Last update Sat Dec 15 20:24:41 2012 maxime ginters
*/

#include "virtual_machine.h"
#include "stdlist.h"
#include "param.h"
#include "corewar.h"

char	*get_prog_name(t_vm *vm, int id)
{
  int	i;
  t_program	*prog;

  i = 0;
  while (i < vm->prog_list->nb_elm)
  {
    prog = get_data(vm->prog_list, i);
    if (prog->prog_param->prog_number == id)
      return (prog->header->prog_name);
    ++i;
  }
  return ("<Error>");
}

int	get_prog_number(t_program *prog, t_vm *vm)
{
  int	id;

  id = (int)prog->registre[0][REG_SIZE - 1];
  if (is_valid_player(vm, id) == 0)
  {
    my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
    prog->active = 0;
    return (-1);
  }
  return (id);
}

int	get_active_prog_count(t_vm *vm)
{
  t_program	*prog;
  int	i;
  int	count;
  int	progs[MAX_PROG_NUMBER];
  int	id;

  my_memset(progs, 0, MAX_PROG_NUMBER * sizeof(int));
  count = 0;
  i = 0;
  while (i < vm->prog_list->nb_elm)
  {
    prog = get_data(vm->prog_list, i);
    if (prog->active == 1)
    {
      id = get_prog_number(prog, vm);
      if (prog->active == 1 && id > 0 && progs[id] != 1 &&
          vm->progs_live[id] != -1)
      {
        progs[id] = 1;
        ++count;
      }
    }
    ++i;
  }
  return (count);
}

t_program	*get_last_active_prog(t_vm *vm)
{
  t_program	*prog;
  int	i;

  i = 0;
  while (i < vm->prog_list->nb_elm)
  {
    prog = get_data(vm->prog_list, i);
    if (prog->active == 1)
      return (prog);
    ++i;
  }
  return (NULL);
}

void	owner_set(int mem_owner[MEM_SIZE], int val, int from, int size)
{
  int	i;

  while (size > MEM_SIZE)
    size -= MEM_SIZE;
  i = 0;
  while (i < size)
  {
    if (from + i >= MEM_SIZE)
    {
      from = 0;
      size -= i;
      i = 0;
    }
    mem_owner[from + i] = val;
    ++i;
  }
}

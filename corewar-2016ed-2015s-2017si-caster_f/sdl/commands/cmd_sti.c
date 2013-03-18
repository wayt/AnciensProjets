/*
** cmd_sti.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:44:35 2012 maxime ginters
** Last update Sat Dec 15 18:04:40 2012 vincent leroy
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

void	parse_sti_param(t_vm *vm, t_program *prog, int param[4][2])
{
  int	i;
  int	j;
  int	pc;

  pc = avance_mem(prog->pc, 1);
  j = 0;
  i = 3;
  while (i >= 0 && j < 4)
  {
    param[j][0] = get_param_type(vm->memory[pc], i);
    param[j][1] = get_size_to_read(vm->memory[pc], i);
    ++j;
    --i;
  }
  if (param[1][0] != PARAM_REG)
    param[1][1] = 2;
  if (param[2][0] != PARAM_REG)
    param[2][1] = 2;
}

int	get_sti_first_data(t_vm *vm, t_program *prog, int *dt, int param[4][2])
{
  int	i;

  i = avance_mem(prog->pc, 2);
  if (vm->memory[i] - 1 < 0 || vm->memory[i] - 1 >= REG_NUMBER)
  {
    my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
    prog->active = 0;
    return (1);
  }
  *dt = getnbr_wsize(prog->registre[vm->memory[i] - 1], 0, REG_SIZE);
  return (0);
}

int	get_sti_second_data(t_vm *vm, t_program *prog, int *dt, int param[4][2])
{
  int	i;

  i = avance_mem(prog->pc, 3);
  if (param[1][0] == PARAM_REG)
  {
    if (vm->memory[i] - 1 < 0 || vm->memory[i] - 1 >= REG_NUMBER)
    {
      my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
      prog->active = 0;
      return (1);
    }
    *dt = getnbr_wsize(prog->registre[vm->memory[i] - 1], 0, REG_SIZE) % IDX_MOD;
  }
  else
    *dt = avance_mem(param[1][0] == PARAM_DIR ? 0 : prog->pc,
        getnbr_wsize(vm->memory, i, IND_SIZE) % IDX_MOD);
  return (0);
}

int	get_sti_third_data(t_vm *vm, t_program *prog, int *dt, int param[4][2])
{
  int	i;

  i = avance_mem(prog->pc, 3);
  if (param[1][0] == PARAM_REG)
  {
    if (vm->memory[i] - 1 < 0 || vm->memory[i] - 1 >= REG_NUMBER)
    {
      my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
      prog->active = 0;
      return (1);
    }
    *dt = getnbr_wsize(prog->registre[vm->memory[i] - 1], 0, REG_SIZE) % IDX_MOD;
  }
  else
    *dt = getnbr_wsize(vm->memory, i, IND_SIZE) % IDX_MOD;
  return (0);
}

int	handle_sti(t_vm *vm, t_program *prog, int index)
{
  int	param[4][2];
  int	data[3];
  int	dest;
  int	i;
  parse_sti_param(vm, prog, param);
  if (get_sti_first_data(vm, prog, &data[0], param) != 0 ||
      get_sti_second_data(vm, prog, &data[1], param) != 0 ||
      get_sti_third_data(vm, prog, &data[2], param) != 0)
    return (0);
  dest = avance_mem(0, data[1] + data[2]);
  i = 0;
  while (i < 4)
  {
    vm->memory[dest] = (data[0] & (0xff << (i * 8)) >> (i * 8));
    vm->mem_owner[dest] = prog->pid;
    if (++dest >= MEM_SIZE)
      dest -= MEM_SIZE;
    ++i;
  }
  (void)index;
  return (2 + 1 + param[1][1] + param[2][1]);
}

/*
** cmd_st.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:35:36 2012 maxime ginters
** Last update Sat Dec 15 17:25:51 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	get_st_src_reg(t_vm *vm, t_program *prog, int *reg)
{
  *reg = vm->memory[avance_mem(prog->pc, 2)] - 1;
  if (*reg < 0 || *reg >= REG_NUMBER)
  {
    my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
    prog->active = 0;
    return (1);
  }
  return (0);
}

int	get_st_dst_reg(t_vm *vm, t_program *prog, int *reg)
{
  *reg = vm->memory[avance_mem(prog->pc, 3)] - 1;
  if (*reg < 0 || *reg >= REG_NUMBER)
  {
    my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
    prog->active = 0;
    return (1);
  }
  return (0);
}

void	copy_reg_to_address(t_vm *vm, t_program *prog, int reg, int addr)
{
  int	i;

  i = 0;
  while (i < REG_SIZE)
  {
    vm->memory[addr] = prog->registre[reg][i];
    vm->mem_owner[addr] = prog->pid;
    if (++addr >= MEM_SIZE)
      addr -= MEM_SIZE;
    ++i;
  }
}

int	handle_st(t_vm *vm, t_program *prog, int index)
{
  int	reg;
  int	tmp;

  if (get_st_src_reg(vm, prog, &reg) != 0)
    return (0);
  if (get_param_type(vm->memory[avance_mem(prog->pc, 1)], 2) == PARAM_REG)
  {
    if (get_st_dst_reg(vm, prog, &tmp) != 0)
      return (0);
    my_memcpy(prog->registre[reg], prog->registre[tmp], REG_SIZE);
    return (4);
  }
  else
  {
    tmp = avance_mem(prog->pc, getnbr_wsize(vm->memory,
          avance_mem(prog->pc, 3), IND_SIZE) % IDX_MOD);
    copy_reg_to_address(vm, prog, reg, tmp);
  }
  return (5);
}

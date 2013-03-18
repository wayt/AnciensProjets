/*
** cmd_or.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:40:46 2012 maxime ginters
** Last update Sat Dec 15 19:35:00 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	get_or_value(t_vm *vm, t_program *prog, int val[2], int param[2][2])
{
  int	i;

  i = -1;
  while (++i < 2)
  {
    if (param[i][0] == PARAM_REG)
    {
      val[i] = vm->memory[avance_mem(prog->pc, 2 + (i == 0 ? 0 :
            param[0][1]))] - 1;
      if (val[i] < 0 || val[i] >= REG_NUMBER)
      {
        my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
        prog->active = 0;
        return (1);
      }
      val[i] = getnbr_wsize(prog->registre[val[i]], 0, REG_SIZE);
    }
    else
    val[i] = getnbr_wsize(vm->memory, avance_mem(prog->pc, 2 + (i == 0 ? 0 :
            param[0][1])), DIR_SIZE);
  }
  return (0);
}

void	get_or_param(t_vm *vm, t_program *prog, int param[2][2])
{
  int	i;

  my_memset(param, 0, 2 * sizeof(int));
  i = 0;
  while (i < 2)
  {
    param[i][0] = get_param_type(vm->memory[avance_mem(prog->pc, 1)], 3 - i);
    param[i][1] = 1;
    if (param[i][0] != PARAM_REG)
      param[i][1] = DIR_SIZE;
    ++i;
  }
}

int	handle_or(t_vm *vm, t_program *prog, int index)
{
  int	param[2][2];
  int	val[2];
  int	reg;

  get_or_param(vm, prog, param);
  if (get_or_value(vm, prog, val, param) != 0)
    return (0);
  reg = vm->memory[avance_mem(prog->pc, 2 + param[0][1] + param[1][1])] - 1;
  if (reg < 0 || reg >= REG_NUMBER)
  {
    my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
    prog->active = 0;
    return (0);
  }
  val[0] = val[0] | val[1];
  prog->carry = (val[0] == 0 ? 1 : 0);
  copy_val_to_reg(prog, reg, val[0]);
  (void)index;
  return (2 + param[0][1] + param[1][1] + 1);
}

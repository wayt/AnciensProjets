/*
** cmd_xor.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:41:52 2012 maxime ginters
** Last update dim. déc. 16 17:26:02 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	get_xor_value(t_vm *vm, t_program *prog, int val[2], int param[2][2])
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
        return (print_segfault(prog, 1));
      val[i] = getnbr_wsize(prog->registre[val[i]], 0, REG_SIZE);
    }
    else
    val[i] = getnbr_wsize(vm->memory, avance_mem(prog->pc, 2 + (i == 0 ? 0 :
            param[0][1])), DIR_SIZE);
  }
  return (0);
}

void	get_xor_param(t_vm *vm, t_program *prog, int param[2][2])
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

int	handle_xor(t_vm *vm, t_program *prog, int index)
{
  int	param[2][2];
  int	val[2];
  int	reg;

  get_xor_param(vm, prog, param);
  if (get_xor_value(vm, prog, val, param) != 0)
    return (0);
  reg = vm->memory[avance_mem(prog->pc, 2 + param[0][1] + param[1][1])] - 1;
  if (reg < 0 || reg >= REG_NUMBER)
    return (print_segfault(prog, 0));
  val[0] = val[0] ^ val[1];
  prog->carry = (val[0] == 0 ? 1 : 0);
  copy_val_to_reg(prog, reg, val[0]);
  (void)index;
  return (2 + param[0][1] + param[1][1] + 1);
}

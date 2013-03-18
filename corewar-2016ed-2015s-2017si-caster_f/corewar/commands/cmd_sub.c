/*
** cmd_sub.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:38:41 2012 maxime ginters
** Last update dim. déc. 16 17:25:05 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	get_sub_reg(t_vm *vm, t_program *prog, int reg[3])
{
  int	i;

  i = 0;
  while (i < 3)
  {
    reg[i] = vm->memory[avance_mem(prog->pc, 2 + i)] - 1;
    if (reg[i] < 0 || reg[i] >= REG_NUMBER)
      return (print_segfault(prog, 1));
    ++i;
  }
  return (0);
}

int	handle_sub(t_vm *vm, t_program *prog, int index)
{
  int	reg[3];
  int	val;
  int	i[2];

  if (get_sub_reg(vm, prog, reg) != 0)
    return (0);
  val = getnbr_wsize(prog->registre[reg[0]], 0, REG_SIZE) -
    getnbr_wsize(prog->registre[reg[1]], 0, REG_SIZE);
  i[0] = REG_SIZE - 1;
  i[1] = 0;
  prog->carry = (val == 0 ? 1 : 0);
  while (i[0] >= 0 && ++i[1] < 4)
  {
    prog->registre[reg[2]][i[0]] = (val & (0xff << (i[1] * 8))) >> (i[1] * 8);
    ++i[1];
    --i[0];
  }
  (void)index;
  return (5);
}

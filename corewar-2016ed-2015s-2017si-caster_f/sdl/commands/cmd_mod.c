/*
** cmd_mod.c for commands in /workspace/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  dim. déc. 16 18:12:29 2012 maxime ginters
** Last update dim. déc. 16 18:23:19 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	get_mod_reg(t_vm *vm, t_program *prog, int reg[3])
{
  int	i;

  i = 0;
  while (i < 3)
  {
    reg[i] = vm->memory[avance_mem(prog->pc, 2 + i)] - 1;
    if (reg[i] < 0 || reg[i] >= REG_NUMBER)
    {
      my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
      prog->active = 0;
      return (1);
    }
    ++i;
  }
  return (0);
}

int	handle_mod(t_vm *vm, t_program *prog, int index)
{
  int	reg[3];
  int	val;
  int	i[2];

  if (get_mod_reg(vm, prog, reg) != 0)
    return (0);
  val = getnbr_wsize(prog->registre[reg[1]], 0, REG_SIZE);
  if (val == 0)
  {
    my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
    prog->active = 0;
    return (0);
  }
  val = getnbr_wsize(prog->registre[reg[0]], 0, REG_SIZE) % val;
  i[0] = REG_SIZE - 1;
  i[1] = 0;
  prog->carry = val != 0 ? 1 : 0;
  while (i[0] >= 0 && ++i[1] < 4)
  {
    prog->registre[reg[2]][i[0]] = (val & (0xff << (i[1] * 8))) >> (i[1] * 8);
    ++i[1];
    --i[0];
  }
  (void)index;
  return (5);
}

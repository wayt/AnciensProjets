/*
** cmd_lldi.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:46:52 2012 maxime ginters
** Last update dim. déc. 16 17:15:37 2012 maxime ginters
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	get_lldi_first_data(t_vm *vm, t_program *prog,
    unsigned char buffer[IND_SIZE], int param[4][2])
{
  int	tmp2;
  int	tmp;
  int	i;

  i = avance_mem(prog->pc, 2);
  if (param[0][0] == PARAM_REG)
  {
    if (vm->memory[i] - 1 < 0 || vm->memory[i] - 1 >= REG_NUMBER)
      return (1);
    tmp = getnbr_wsize(prog->registre[vm->memory[i] - 1], 0, REG_SIZE);
  }
  else
    tmp = getnbr_wsize(vm->memory, avance_mem(param[0][0] == PARAM_IND ?
      prog->pc : 0, getnbr_wsize(vm->memory, i, param[0][1])), IND_SIZE);
  i = -1;
  tmp2 = IND_SIZE - 1;
  while (++i < IND_SIZE && tmp2 >= 0)
    buffer[tmp2--] = (tmp & (0xff << (i * 8))) >> (i * 8);
  return (0);
}

int	get_lldi_second_data(t_vm *vm, t_program *prog, int *data,
    int param[4][2])
{
  int	i;

  i = avance_mem(prog->pc, 2 + param[0][1]);
  if (param[1][0] == PARAM_REG)
  {
    if (vm->memory[i] - 1 < 0 || vm->memory[i] - 1 >= REG_NUMBER)
      return (1);
    *data = getnbr_wsize(prog->registre[vm->memory[i] - 1], 0, REG_SIZE);
  }
  else
    *data = getnbr_wsize(vm->memory, i, param[1][1]);
  return (0);
}

void	parse_lldi_param(t_vm *vm, t_program *prog, int param[4][2])
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
  if (param[0][0] != PARAM_REG)
    param[0][1] = 2;
  if (param[1][0] != PARAM_REG)
    param[1][1] = 2;
}

int	handle_lldi(t_vm *vm, t_program *prog, int index)
{
  unsigned char	buffer[IND_SIZE];
  int	param[4][2];
  int	i;
  int	reg;

  my_memset(buffer, 0, IND_SIZE);
  parse_lldi_param(vm, prog, param);
  if (get_lldi_first_data(vm, prog, buffer, param) != 0 ||
      get_lldi_second_data(vm, prog, &i, param) != 0)
    return (print_segfault(prog, 0));
  i = avance_mem(prog->pc, i + avance_mem(param[0][0] == PARAM_DIR ? 0 :
          prog->pc,getnbr_wsize(buffer, 0, IND_SIZE)));
  reg = avance_mem(prog->pc, 2 + param[0][1] + param[1][1]);
  if (vm->memory[reg] - 1 < 0 || vm->memory[reg] - 1 >= REG_NUMBER)
    return (print_segfault(prog, 0));
  prog->carry = (getnbr_wsize(vm->memory, i, REG_SIZE) == 0 ? 1 : 0);
  mem_safecpy(prog->registre[vm->memory[reg] - 1], vm->memory, i, REG_SIZE);
  (void)index;
  return (2 + param[0][1] + param[1][1] + 1);
}

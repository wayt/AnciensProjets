/*
** cmd_ld.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 18:34:41 2012 maxime ginters
** Last update dim. déc. 16 17:10:08 2012 maxime ginters
*/

#include "my.h"
#include "corewar.h"
#include "virtual_machine.h"
#include "commands.h"

int	get_ld_data(t_vm *vm, t_program *prog, unsigned char data[REG_SIZE])
{
  char	type;
  int	i;
  int	tmp;

  i = avance_mem(prog->pc, 2);
  type = get_param_type(vm->memory[avance_mem(prog->pc, 1)], 3);
  tmp = get_size_to_read(vm->memory[avance_mem(prog->pc, 1)], 3);
  if (type == PARAM_REG)
  {
    if (vm->memory[i] - 1 < 0 || vm->memory[i] - 1 >= REG_NUMBER)
      return (1);
    my_memcpy(data, &prog->registre[vm->memory[i] - 1], REG_SIZE);
    return (0);
  }
  tmp = avance_mem(0, getnbr_wsize(vm->memory,
        avance_mem(prog->pc, 2), tmp) % IDX_MOD);
  if (type == PARAM_IND)
    i = avance_mem(prog->pc, tmp);
  mem_safecpy(data, vm->memory, avance_mem(prog->pc, (i % IDX_MOD)), REG_SIZE);
  return (0);
}

void	mod_ld_carry(t_program *prog, unsigned char data[REG_SIZE])
{
  int	i;

  i = 0;
  while (i < REG_SIZE)
  {
    if (data[i] != 0)
    {
      prog->carry = 0;
      return;
    }
    ++i;
  }
  prog->carry = 1;
}

int	handle_ld(t_vm *vm, t_program *prog, int index)
{
  unsigned char	data[REG_SIZE];
  int	size;
  int	dest_reg;

  my_memset(data, 0, REG_SIZE);
  size = get_size_to_read(vm->memory[avance_mem(prog->pc, 1)], 3);
  dest_reg = vm->memory[avance_mem(prog->pc, 2 + size)] - 1;
  if (dest_reg < 0 || dest_reg >= REG_NUMBER || get_ld_data(vm, prog, data))
    return (print_segfault(prog, 0));
  mod_ld_carry(prog, data);
  my_memcpy(&prog->registre[dest_reg], data, REG_SIZE);
  (void)index;
  return (2 + size + 1);
}

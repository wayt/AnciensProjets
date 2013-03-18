/*
** vm_launcher.c for virtual_machine in /home/fest/Epitech/CoreWar/core/virtual_machine
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Dec 05 17:35:59 2012 maxime ginters
** Last update Sun Dec 16 18:21:00 2012 vincent leroy
*/

#include <fcntl.h>
#include "virtual_machine.h"
#include "my.h"
#include "op.h"
#include "corewar.h"
#include "stdlist.h"

int	mem_reader(t_vm *vm, int fd, t_program *prog)
{
  int	to_read;
  int	mem_offset;
  int	rd;

  mem_offset = prog->prog_param->load_address;
  to_read = prog->header->prog_size;
  while (to_read > 0)
  {
    rd = to_read;
    if (mem_offset + to_read > MEM_SIZE)
      rd = MEM_SIZE - mem_offset;
    if ((rd = read(fd, vm->memory + mem_offset, rd)) == 0)
      return (1);
    to_read -= rd;
    if (to_read > 0)
      mem_offset = 0;
  }
  return (0);
}

t_program	*create_program(t_prog_param *param)
{
  t_program	*new;

  if ((new = my_malloc(sizeof(t_program), MALLOC_FAIL)) == 0)
    return (NULL);
  new->sleep = 0;
  new->active = 1;
  new->carry = 1;
  new->prog_param = param;
  new->registre[0][REG_SIZE - 1] = (char)param->prog_number;
  new->pc = param->load_address;
  new->pid = param->prog_number;
  return (new);
}

t_program	*load_program(t_prog_param *prog, t_vm *vm)
{
  t_program	*program;
  int	fd;

  if ((fd = open(prog->prog_name, O_RDONLY)) == 0)
    return (NULL);
  if ((program = create_program(prog)) == 0)
    return (NULL);
  if ((program->header = my_malloc(sizeof(header_t), MALLOC_FAIL)) == 0)
    return (NULL);
  if (read(fd, program->header, sizeof(header_t)) <= 0)
    return (NULL);
  if (endian_cmp(program->header->magic, COREWAR_EXEC_MAGIC) == 0)
  {
    my_printf("%s: Invalide corewar file ...\n", prog->prog_name);
    return (NULL);
  }
  if (is_big_endian() == 0)
    program->header->prog_size = swap_int(program->header->prog_size);
  if (mem_reader(vm, fd, program) == 1)
    return (NULL);
  vm->register_player[program->pid] = 1;
  return (program);
}

int	load_all_programs(t_vm *vm)
{
  int	i;
  t_prog_param	*prog;
  t_program	*program;

  if ((vm->prog_list = create_list(NULL)) == 0)
    return (1);
  i = 0;
  while (i < vm->param->progs->nb_elm)
  {
    prog = get_data(vm->param->progs, i);
    program = NULL;
    if ((program = load_program(prog, vm)) == 0)
    {
      my_printf("Error: fail to load : %s\n", prog->prog_name);
      return (1);
    }
    add_last_elm(vm->prog_list, program);
    vm->progs_live[program->registre[0][REG_SIZE - 1]] = 0;
    ++i;
  }
  return (0);
}

int	launch_vm(t_param *param)
{
  t_vm	*vm;
  int	i;

  if ((vm = my_malloc(sizeof(t_vm), "Error: fail to malloc vm\n")) == 0)
    return (1);
  vm->param = param;
  vm->cycle = 0;
  vm->cycle_to_die = CYCLE_TO_DIE;
  vm->nb_live = 0;
  i = 0;
  while (i < MAX_PROG_NUMBER)
    vm->progs_live[i++] = -1;
  if (load_all_programs(vm) != 0)
    return (1);
  my_printf("%d program(s) loaded\n", vm->prog_list->nb_elm);
  if (param->debug == 1)
    dump_memory(vm->memory);
  return (vm_run(vm));
}

/*
** virtual_machine.h for virtual_machine in /home/fest/Epitech/CoreWar/core/virtual_machine
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Dec 05 17:31:05 2012 maxime ginters
** Last update Sat Dec 15 20:34:13 2012 maxime ginters
*/

#ifndef VIRTUAL_MACHINE_H_
# define VIRTUAL_MACHINE_H_

#include "op.h"
#include "param.h"
#include "corewar.h"

#define PARAM_REG 1
#define PARAM_DIR 2
#define PARAM_IND 3

#define MAX_PROG_NUMBER 255

#define MAX_PLAYER 4

struct s_vm
{
  t_param	*param;
  unsigned char	memory[MEM_SIZE];
  char	register_player[MAX_PLAYER + 1];
  unsigned int	cycle;
  unsigned int	cycle_to_die;
  int	nb_live;
  int	progs_live[MAX_PROG_NUMBER];
  t_list	*prog_list;
};

typedef struct s_vm t_vm;

/*
** vm_launcher.c
*/
int	launch_vm(t_param *param);
void	dump_memory(unsigned char *mem);

/*
** endian_tools.c
*/
int	is_big_endian();
int	swap_int(int val);
int	endian_cmp(int val, int ref);

/*
** vm_run.c
*/
int	vm_run(t_vm* vm);

/*
** vm_tools.c
*/
char	*get_prog_name(t_vm *vm, int id);
int	get_prog_number(t_program *prog, t_vm *vm);
int	get_active_prog_count(t_vm *vm);
t_program	*get_last_active_prog(t_vm *vm);

/*
** corewar.c
*/
int	is_valid_player(t_vm *vm, int nb);

#endif /* !VIRTUAL_MACHINE_H_ */

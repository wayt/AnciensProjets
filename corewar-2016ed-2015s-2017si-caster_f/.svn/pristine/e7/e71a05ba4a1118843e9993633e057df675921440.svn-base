/*
** commands.h for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 15:22:08 2012 maxime ginters
** Last update dim. déc. 16 18:14:50 2012 maxime ginters
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_

#include "my.h"
#include "virtual_machine.h"
#include "corewar.h"

struct s_cw_cmd
{
  char	cmd;
  int	sleep;
  int	(*funct)(t_vm*, t_program*, int);
  char	*name;
};

typedef struct s_cw_cmd t_cw_cmd;

extern t_cw_cmd	corewar_commands[];

/*
** commands.c
*/
char	get_param_type(unsigned char oct, char index);
int	get_size_to_read(unsigned char oct, char index);
int	avance_mem(int pc, int count);
unsigned char	*mem_safecpy(unsigned char *dest, unsigned char *mem,
    int from, int size);
int	getnbr_wsize(unsigned char *mem, int pc, int size);

/*
** commands
*/
int	handle_live(t_vm *vm, t_program *prog, int index);
int	handle_ld(t_vm *vm, t_program *prog, int index);
int	handle_st(t_vm *vm, t_program *prog, int index);
int	handle_add(t_vm *vm, t_program *prog, int index);
int	handle_sub(t_vm *vm, t_program *prog, int index);
int	handle_and(t_vm *vm, t_program *prog, int index);
int	handle_or(t_vm *vm, t_program *prog, int index);
int	handle_xor(t_vm *vm, t_program *prog, int index);
int	handle_zjmp(t_vm *vm, t_program *prog, int index);
int	handle_ldi(t_vm *vm, t_program *prog, int index);
int	handle_sti(t_vm *vm, t_program *prog, int index);
int	handle_fork(t_vm *vm, t_program *prog, int index);
int	handle_lld(t_vm *vm, t_program *prog, int index);
int	handle_lldi(t_vm *vm, t_program *prog, int index);
int	handle_lfork(t_vm *vm, t_program *prog, int index);
int	handle_aff(t_vm *vm, t_program *prog, int index);
int	handle_mul(t_vm *vm, t_program *prog, int index);
int	handle_div(t_vm *vm, t_program *prog, int index);
int	handle_mod(t_vm *vm, t_program *prog, int index);

/*
** cmd_and.c
*/
void	copy_val_to_reg(t_program *prog, int reg, int val);

/*
** sdl_utils.c
*/
void	update_owner(int old, int niu, t_vm *vm);

/*
** messages.c
*/
int	print_segfault(t_program *prog, int ret);

#endif /* !COMMANDS_H_ */

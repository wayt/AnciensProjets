/*
** corewar.h for core in /home/fest/Epitech/corewar-2016ed-2015s-2017si-caster_f/core
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Dec 04 16:53:51 2012 maxime ginters
** Last update Sat Dec 15 20:33:56 2012 maxime ginters
*/

#ifndef COREWAR_H_
# define COREWAR_H_

#include "param.h"
#include "op.h"

#define MAX_PLAYER 4

struct s_program
{
  header_t	*header;
  t_prog_param	*prog_param;
  int	pc;
  int	sleep;
  char	active;
  char	carry;
  int	pid;
  unsigned int	last_live;
  unsigned char	registre[REG_NUMBER][REG_SIZE];
};

typedef struct s_program	t_program;

struct s_command
{
  char	com;
  char	control;
  char	param[4];
};

typedef struct s_command	t_command;

/*
** corewar.c
*/
int	get_new_pid();

#endif /* !COREWAR_H_ */

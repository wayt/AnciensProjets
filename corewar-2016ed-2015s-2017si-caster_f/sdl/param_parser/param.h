/*
** param.h for param_parser in /home/fest/Epitech/CoreWar/Core/param_parser
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Dec 04 01:37:44 2012 maxime ginters
** Last update Tue Dec 11 11:16:33 2012 vincent leroy
*/

#ifndef PARAM_H_
# define PARAM_H_

#include "stdlist.h"

struct s_prog_param
{
  int	prog_number;
  int	load_address;
  char	*prog_name;
};

typedef struct s_prog_param t_prog_param;

struct s_param
{
  int		nbr_cycle;
  char		debug;
  int		prog_count;
  t_list	*progs;
};

typedef struct s_param t_param;

/*
** param_parser.c
*/
t_param		*init_param(int prog_count);
t_prog_param	*init_prog_param(int prog_count);
int		get_prog_count(int ac, char **av);
t_param		*create_param(int ac, char **av);

/*
** param_cleaner.c
*/
void	free_prog_param(t_prog_param *elm);

/*
** param_setter.c
*/
void	set_prog_number(t_prog_param **prog, int nbr, int prog_count);
void	set_prog_address(t_prog_param **prog, int nbr, int prog_count);
void	set_prog_name(t_prog_param **prog, char *name, int prog_count);


#endif /* !PARAM_H_ */

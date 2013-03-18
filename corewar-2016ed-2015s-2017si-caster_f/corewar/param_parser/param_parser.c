/*
** param_parser.c for param_parser in /home/fest/Epitech/CoreWar/Core/param_parser
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Dec 04 01:45:35 2012 maxime ginters
** Last update dim. déc. 16 17:37:57 2012 maxime ginters
*/

#include <stdlib.h>
#include "stdlist.h"
#include "my.h"
#include "param.h"
#include "op.h"
#include "corewar.h"

t_param	*init_param(int prog_count)
{
  t_param	*param;

  if ((param = malloc(sizeof(t_param))) == 0)
    return (NULL);
  param->nbr_cycle = 0;
  param->debug = 0;
  param->progs = create_list(NULL);
  param->prog_count = prog_count;
  return (param);
}

t_prog_param	*init_prog_param(int prog_count)
{
  t_prog_param	*param;

  if ((param = malloc(sizeof(t_prog_param))) == 0)
    return (NULL);
  set_prog_number(&param, -1, prog_count);
  if (param == NULL)
    return (NULL);
  set_prog_address(&param, -1, prog_count);
  param->prog_name = NULL;
  return (param);
}

int	get_prog_count(int ac, char **av)
{
  int	i;
  int	count;

  count = 0;
  i = 1;
  while (i < ac)
  {
    if (!(my_strcmp(av[i], "-dump") == 0 ||
      my_strcmp(av[i], "-n") == 0 ||
      my_strcmp(av[i], "-a") == 0 ||
      my_strcmp(av[i], "-debug") == 0))
      ++count;
    ++i;
  }
  return (count);
}

int	parse_param(t_param *param, t_prog_param **prog, int *i, char **av)
{
  if (my_strcmp(av[*i], "-dump") == 0 && av[*i + 1] != NULL)
    param->nbr_cycle = my_getnbr(av[++*i]);
  else if (my_strcmp(av[*i], "-n") == 0 && av[*i + 1] != NULL)
    set_prog_number(prog, my_getnbr(av[++*i]), param->prog_count);
  else if (my_strcmp(av[*i], "-a") == 0 && av[*i + 1] != NULL)
    set_prog_address(prog, my_getnbr(av[++*i]), param->prog_count);
  else if (my_strcmp(av[*i], "-debug") == 0)
    param->debug = 1;
  else
  {
    set_prog_name(prog, av[*i], param->prog_count);
    if (add_last_elm(param->progs, *prog) != 0)
    {
      my_printf("Error: fail to add prog in list while parsing params...\n");
      return (1);
    }
    *prog = NULL;
  }
  return (0);
}

t_param	*create_param(int ac, char **av)
{
  int	i;
  t_param	*param;
  t_prog_param	*prog;
  int	prog_count;

  if ((prog_count = get_prog_count(ac, av)) == 0)
    return (NULL);
  if (prog_count > MAX_PLAYER)
  {
    my_printf("Error: to many programs !\n");
    return (NULL);
  }
  if ((param = init_param(prog_count)) == 0)
    return (NULL);
  prog = NULL;
  i = 1;
  while (i < ac)
  {
    if (parse_param(param, &prog, &i, av) != 0)
      return (NULL);
    ++i;
  }
  return (param);
}


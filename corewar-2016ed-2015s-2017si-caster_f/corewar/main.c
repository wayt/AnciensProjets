/*
** main.c for Core in /home/fest/Epitech/CoreWar/Core
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Dec 04 01:36:06 2012 maxime ginters
** Last update Sat Dec 15 16:01:29 2012 vincent leroy
*/

#include "stdlist.h"
#include "my.h"
#include "param.h"
#include "virtual_machine.h"

void	params_help()
{
  my_printf("Usage: ./corewar [-dump nbr_cycle] [[-n prog_number]");
  my_printf(" [-a load_address] prog_name] ...\n");
}

void	print_params(t_param *params)
{
  int	i;
  t_prog_param	*prog;

  my_printf("dump : %d\n", params->nbr_cycle);
  i = 0;
  while (i < params->progs->nb_elm)
  {
    prog = get_data(params->progs, i);
    my_printf("Name : %s - number : %d - load addr : %d\n", prog->prog_name,
        prog->prog_number, prog->load_address);
    ++i;
  }
}

int	main(int argc, char **argv)
{
  t_param	*params;
  int	ret;

  if ((params = create_param(argc, argv)) == 0)
  {
    params_help();
    return (1);
  }
  if (params->debug == 1)
    print_params(params);
  ret = launch_vm(params);
  del_all_list(&params->progs, free_prog_param, NULL);
  free(params);
  return (ret);
}

/*
** param_setter.c for param_parser in /home/fest/Epitech/CoreWar/core/param_parser
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Dec 05 17:04:32 2012 maxime ginters
** Last update Sun Dec 16 19:07:15 2012 fabien casters
*/

#include <stdlib.h>
#include "virtual_machine.h"
#include "stdlist.h"
#include "my.h"
#include "param.h"
#include "op.h"

void	set_prog_number(t_prog_param **prog, int nbr, int prog_count)
{
  static int	prog_nbr = 1;

  if (*prog == NULL)
    if ((*prog = init_prog_param(prog_count)) == 0)
    {
      my_printf("Error: fail to malloc in set_prog_number\n");
      return;
    }
  if (nbr < prog_nbr && nbr != -1)
    my_printf("Error: invalide prog number : %d, set to default : %d\n", nbr,
        prog_nbr);
  if (nbr == -1 || nbr < prog_nbr)
    (*prog)->prog_number = prog_nbr++;
  else
  {
    (*prog)->prog_number = nbr;
    prog_nbr = nbr + 1;
  }
  if ((*prog)->prog_number > MAX_PLAYER)
  {
    my_printf("Error: max prog number is %d\n", MAX_PLAYER);
    exit(1);
  }
}

void	set_prog_address(t_prog_param **prog, int addr, int prog_count)
{
  static int	load_addr = 0;

  if (*prog == NULL)
    if ((*prog = init_prog_param(prog_count)) == 0)
    {
      my_printf("Error: fail to malloc in set_prog_address\n");
      return;
    }

  if (addr >= MEM_SIZE && addr != -1)
    my_printf("Error: invalide prog address : %d, set to default : %d\n", addr,
        load_addr);
  if (addr == -1 || addr >= MEM_SIZE)
  {
    (*prog)->load_address = load_addr;
    if ((load_addr += (MEM_SIZE / prog_count)) > MEM_SIZE)
      load_addr -= MEM_SIZE;
  }
  else
    (*prog)->load_address = addr;
}

void	set_prog_name(t_prog_param **prog, char *name, int prog_count)
{
  if (*prog == NULL)
    if ((*prog = init_prog_param(prog_count)) == 0)
    {
      my_printf("Error: Fail to malloc in set_prog_name\n");
      return;
    }
  (*prog)->prog_name = my_strdup(name);
}

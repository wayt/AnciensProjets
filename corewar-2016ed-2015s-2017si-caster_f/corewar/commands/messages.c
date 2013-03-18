/*
** messages.c for commands in /workspace/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  dim. déc. 16 17:01:42 2012 maxime ginters
** Last update dim. déc. 16 17:12:32 2012 maxime ginters
*/

#include "my.h"
#include "commands.h"

int	print_segfault(t_program *prog, int ret)
{
  my_printf("%s : erreur de segmentation\n", prog->header->prog_name);
  prog->active = 0;
  return (ret);
}

/*
** functions.c for etape_2 in /home/fest/Epitech/rush1-2017-ginter_m/etape_2
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Dec 01 00:37:56 2012 maxime ginters
** Last update Sat Dec 01 01:18:02 2012 maxime ginters
*/

#include <stdlib.h>
#include "create_platine.h"
#include "commandes_parser.h"
#include "functions.h"

t_functions	funct_tab[] = {
  {'P', handle_play},
  {'p', handle_pause},
  {'r', handle_rewind},
  {'f', handle_forward},
  {'\0', NULL}
};

void	handle_play(t_platine *pa, t_platine *pb, t_command* cmd)
{
  if (cmd->commands[cmd->index][1] == 'a')
    pa->active = 1;
  else if (cmd->commands[cmd->index][1] == 'b')
    pb->active = 1;
}

void	handle_pause(t_platine *pa, t_platine *pb, t_command* cmd)
{
  if (cmd->commands[cmd->index][1] == 'a')
    pa->active = 0;
  else if (cmd->commands[cmd->index][1] == 'b')
    pb->active = 0;
}

void	handle_rewind(t_platine *pa, t_platine *pb, t_command* cmd)
{
  if (cmd->commands[cmd->index][1] == 'a')
  {
    if (--pa->index < 0)
      pa->index = 0;
  }
  else if (cmd->commands[cmd->index][1] == 'b')
  {
    if (--pb->index < 0)
      pb->index = 0;
  }

}

void	handle_forward(t_platine *pa, t_platine *pb, t_command* cmd)
{
  if (cmd->commands[cmd->index][1] == 'a')
  {
    if (pa->cmd[pa->index] == NULL)
      return;
    ++pa->index;
  }
  else if (cmd->commands[cmd->index][1] == 'b')
  {
    if (pb->cmd[pb->index] == NULL)
      return;
    ++pb->index;
  }
}

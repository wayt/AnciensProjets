/*
** functions.c for etape_2 in /home/fest/Epitech/rush1-2017-ginter_m/etape_2
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Dec 01 00:37:56 2012 maxime ginters
** Last update Sat Dec 01 21:07:31 2012 maxime ginters
*/

#include <stdio.h>
#include <stdlib.h>
#include "create_platine.h"
#include "commandes_parser.h"
#include "functions.h"

t_functions	funct_tab[] = {
  {'P', handle_play},
  {'p', handle_pause},
  {'r', handle_rewind},
  {'f', handle_forward},
  {'R', handle_reverse},
  {'C', handle_cue},
  {'c', handle_cut},
  {'F', handle_fx},
  {'\0', NULL}
};

void	handle_play(t_platine *pa, t_platine *pb, t_command* cmd)
{
  if (cmd->commands[cmd->index]->param1 == 'a')
    pa->active = 1;
  else if (cmd->commands[cmd->index]->param1 == 'b')
    pb->active = 1;
}

void	handle_pause(t_platine *pa, t_platine *pb, t_command* cmd)
{
  if (cmd->commands[cmd->index]->param1 == 'a')
    pa->active = 0;
  else if (cmd->commands[cmd->index]->param1 == 'b')
    pb->active = 0;
}

void	handle_rewind(t_platine *pa, t_platine *pb, t_command* cmd)
{
  if (cmd->commands[cmd->index]->param1 == 'a')
  {
    if (--pa->index < 0)
      pa->index = 0;
  }
  else if (cmd->commands[cmd->index]->param1 == 'b')
  {
    if (--pb->index < 0)
      pb->index = 0;
  }

}

void	handle_forward(t_platine *pa, t_platine *pb, t_command* cmd)
{
  if (cmd->commands[cmd->index]->param1 == 'a')
  {
    if (pa->cmd[pa->index] == NULL)
      return;
    ++pa->index;
  }
  else if (cmd->commands[cmd->index]->param1 == 'b')
  {
    if (pb->cmd[pb->index] == NULL)
      return;
    ++pb->index;
  }
}

void	handle_reverse(t_platine *pa, t_platine *pb, t_command* cmd)
{
  if (cmd->commands[cmd->index]->param1 == 'a')
  {
    if (pa->reversed == 0)
      --pa->index;
    else
      ++pa->index;
    pa->reversed = !pa->reversed;
  }
  else if (cmd->commands[cmd->index]->param1 == 'b')
  {
    if (pb->reversed == 0)
      --pb->index;
    else
      ++pb->index;
    pb->reversed = !pb->reversed;
  }
}


/*
** handle_fx.c for etape_4 in /home/fest/Epitech/rush1-2017-ginter_m/etape_4
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Dec 01 21:07:59 2012 maxime ginters
** Last update Sat Dec  1 22:14:33 2012 alexandre sivadon
*/

#include <string.h>
#include "commandes_parser.h"
#include "create_platine.h"
#include "functions.h"

void	reset_all_fx(t_platine *p)
{
  p->lowpass = 0;
  p->highpass = 0;
  p->doubl = 0;
  p->flanger = 0;
  p->echo = 0;
}

void	handle_fx(t_platine *pa, t_platine *pb, t_command *cmd)
{
  t_platine	*p;

  p = NULL;
  if (cmd->commands[cmd->index]->param1 == 'a')
    p = pa;
  else if (cmd->commands[cmd->index]->param1 == 'b')
    p = pb;
  if (!p)
    return;

  if (strcmp(cmd->commands[cmd->index]->param2, "filter_lowpass") == 0)
    p->lowpass = 1;
  else if (strcmp(cmd->commands[cmd->index]->param2, "filter_highpass") == 0)
    p->highpass = 1;
  else if (strcmp(cmd->commands[cmd->index]->param2, "double") == 0)
    p->doubl = 1;
  else if (strcmp(cmd->commands[cmd->index]->param2, "flanger") == 0)
    p->flanger = 1;
  else if (strcmp(cmd->commands[cmd->index]->param2, "echo") == 0)
    p->echo = 1;
}

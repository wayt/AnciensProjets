/*
** cue.c for  in /home/sivado_a//Documents/rendus/rush1-2017-ginter_m/etape_3
** 
** Made by alexandre sivadon
** Login   <sivado_a@epitech.net>
** 
** Started on  Sat Dec  1 02:40:17 2012 alexandre sivadon
** Last update Sat Dec 01 17:14:39 2012 maxime ginters
*/

#include <stdio.h>
#include "create_platine.h"
#include "commandes_parser.h"
#include "functions.h"

#define PARAM2 cmd->commands[cmd->index]->param2

int	hidenp(char *s1, char *s2)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (s1[i] && s2[j])
    {
      if (s1[i] == s2[j])
        i++;
      j++;
    }
  if (s1[i] == '\0')
    return (1);
  else
    return (0);
}

void	handle_cue(t_platine *pa, t_platine *pb, t_command* cmd)
{
  int	i;

  i = 0;
  if (cmd->commands[cmd->index]->param1 == 'a')
    {
      while (pa->cmd[i])
	{
	  if (hidenp(PARAM2, pa->cmd[i]) == 1)
          {
            pa->index = i;
            return;
          }
	  i++;
	}
    }
  else if (cmd->commands[cmd->index]->param1 == 'b')
    {
      while (pb->cmd[i])
	{
	  if (hidenp(PARAM2, pb->cmd[i]) == 1)
          {
            pb->index = i;
            return;
          }
          i++;
	}
    }
}

/*
** main.c for etape_2 in /home/fest/Epitech/rush1-2017-ginter_m/etape_2
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Dec 01 00:11:08 2012 maxime ginters
** Last update Sat Dec 01 17:13:53 2012 maxime ginters
*/

#include <stdio.h>
#include "commandes_parser.h"
#include "create_platine.h"
#include "functions.h"
#include "play.h"

int	process_command(t_platine *pa, t_platine *pb, t_command *cmd)
{
  int	i;

  if (cmd->commands[cmd->index] == NULL)
    return (0);
  i = 0;
  while (funct_tab[i].c != '\0')
  {
    if (cmd->commands[cmd->index]->cmd == funct_tab[i].c)
      (funct_tab[i].funct)(pa, pb, cmd);
    ++i;
  }
  ++cmd->index;
  return (1);
}

void	run_dj(t_platine *pa, t_platine *pb, t_command *cmd)
{
  while ((pa->index >= 0 && pa->cmd[pa->index]) || (pb->index >= 0 && pb->cmd[pb->index]))
  {
    if (process_command(pa, pb, cmd) == 0)
      return;
    if (pa->active == 1 && pb->active == 1)
    {
      if (pa->index >= 0 && pb->index >= 0 && pa->cmd[pa->index] && pb->cmd[pb->index])
        printf("%s_%s\n", play(pa), play(pb));
      else
        printf("%s\n", pa->cmd[pa->index] && pa->index >= 0 ? play(pa) : play(pb));
    }
    else if ((pa->active == 1 && pa->index >= 0) || (pb->active == 1 && pb->index >= 0))
      printf("%s\n", pa->active == 1 && pa->index >= 0 ? play(pa) : play(pb));
    else
      printf("\n");
    pa->index += (pa->index < 0 ? 0 : (pa->cmd[pa->index] ? (pa->reversed ? -1 : 1) : 0));
    pb->index += (pb->index < 0 ? 0 : (pb->cmd[pb->index] ? (pb->reversed ? -1 : 1) : 0));
  }
}

int	main(int ac, char **av)
{
  t_platine	*platine_a;
  t_platine	*platine_b;
  t_command	*commands;

  if (ac < 3)
  {
    printf("Usage: ./%s platineA platineB < commandes\n", av[0]);
    return (1);
  }
  platine_a = create_platine(av[1]);
  platine_b = create_platine(av[2]);
  commands = read_commands();

  if (!platine_a || !platine_b || !commands)
  {
    printf("Error while getting platine or commands\n");
    return (1);
  }
  run_dj(platine_a, platine_b, commands);
  return (0);
}

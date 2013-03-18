/*
** commandes_parser.c for etape_2 in /home/fest/Epitech/rush1-2017-ginter_m/etape_2
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Nov 30 22:58:15 2012 maxime ginters
** Last update Sat Dec 01 17:25:58 2012 maxime ginters
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "commandes_parser.h"

t_command	*create_new_command()
{
  t_command	*new;

  if ((new = malloc(sizeof(t_command))) == 0)
      return (NULL);
  if ((new->commands = malloc(sizeof(char*))) == 0)
    return (NULL);
  new->commands[0] = NULL;
  new->index = 0;
  return (new);
}

t_command	*read_commands()
{
  char	*buff;
  t_command	*new;
  int	i;
  size_t	len;
  int	read;

  if ((new = create_new_command()) == 0)
    return (NULL);

  buff = NULL;
  i = 0;
  while ((read = getline(&buff, &len, stdin)) != -1)
    if (read >= 1)
    {
      new->commands[i] = malloc(2 * sizeof(char));
      new->commands[i][0] = buff[1] == 'l' ? 'P' :
        (buff[0] == '\n' ? '0' : buff[0]);
      new->commands[i][1] = (read > 1 ? buff[read - 2] : '0');
      new->commands = realloc(new->commands, (i + 2) * sizeof(char*));
      ++i;
    }
  new->commands[i] = NULL;
  return (new);
}

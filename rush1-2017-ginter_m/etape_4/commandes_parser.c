/*
** commandes_parser.c for etape_2 in /home/fest/Epitech/rush1-2017-ginter_m/etape_2
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Nov 30 22:58:15 2012 maxime ginters
** Last update Sat Dec 01 21:06:31 2012 maxime ginters
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "commandes_parser.h"

char	get_cmd(char *buff)
{
  if (strcmp(buff, "play") == 0)
    return ('P');
  else if (strcmp(buff, "pause") == 0)
    return ('p');
  else if (strcmp(buff, "rewind") == 0)
    return ('r');
  else if (strcmp(buff, "forward") == 0)
    return ('f');
  else if (strcmp(buff, "cut") == 0)
    return ('c');
  else if (strcmp(buff, "reverse") == 0)
    return ('R');
  else if (strcmp(buff, "cue") == 0)
    return ('C');
  else if (strcmp(buff, "fx") == 0)
    return ('F');
  return ('0');
}

t_cmd_info	*create_cmd_info(char *buff)
{
  t_cmd_info	*new;
  char	*fh;

  if ((new = malloc(sizeof(t_cmd_info))) == 0)
    return (NULL);
  new->cmd = '0';
  new->param2 = NULL;
  new->param1 = '0';
  if ((fh = strtok(buff, " ")) == 0)
    return (new);
  new->cmd = get_cmd(fh);
  if ((fh = strtok(NULL, " ")) != 0)
  {
    if (new->cmd == 'F')
      new->param2 = strdup(fh);
    else
      new->param1 = fh[0];
  }
  if ((fh = strtok(NULL, " ")) != 0)
  {
    if (new->cmd == 'F')
      new->param1 = fh[0];
    else
    {
      if ((new->param2 = malloc((strlen(fh) + 2) * sizeof(char))) == 0)
        return (NULL);
      new->param2[0] = ':';
      new->param2[1] = '\0';
      new->param2 = strcat(new->param2, fh);
    }
  }
  return (new);
}

t_command	*create_new_command()
{
  t_command	*new;

  if ((new = malloc(sizeof(t_command))) == 0)
      return (NULL);
  if ((new->commands = malloc(sizeof(t_cmd_info*))) == 0)
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
      buff[read - 1] = '\0';
      if ((new->commands[i] = create_cmd_info(buff)) == 0)
        return (NULL);
      new->commands = realloc(new->commands, (i + 2) * sizeof(t_cmd_info*));
      ++i;
    }
  new->commands[i] = NULL;
  return (new);
}

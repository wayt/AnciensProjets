/*
** create_platine.c for  in /home/sivado_a//Documents/rendus/rush1-2017-ginter_m/etape_2
** 
** Made by alexandre sivadon
** Login   <sivado_a@epitech.net>
** 
** Started on  Fri Nov 30 22:52:15 2012 alexandre sivadon
** Last update Sat Dec  1 22:10:04 2012 alexandre sivadon
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "create_platine.h"

t_platine	*create_new_platine()
{
  t_platine	*new;

  if ((new = malloc(sizeof(t_platine))) == 0)
    return (NULL);
  if ((new->cmd = malloc(1 * sizeof(char*))) == 0)
      return (NULL);
  new->index = 0;
  new->active = 1;
  new->reversed = 0;
  reset_all_fx(new);
  return (new);
}

t_platine	*create_platine(char *file)
{
  t_platine	*platine;
  FILE	*fp;
  size_t	len;
  int	read;
  char	*buff;
  int	i;

  if ((fp = fopen(file, "r")) == 0)
    return (NULL);
  if ((platine = create_new_platine()) == 0)
    return (NULL);
  buff = NULL;
  i = -1;
  while ((read = getline(&buff, &len, fp)) != -1)
    if (i++ >= 0)
    {
      buff[read - 1] = '\0';
      platine->cmd[i - 1] = strdup(buff);
      platine->cmd = realloc(platine->cmd, (i + 1) * sizeof(char*));
    }
  platine->cmd[i] = NULL;
  fclose(fp);
  return (platine);
}

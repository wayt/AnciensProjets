/*
** params_parser.c for my_script in /Storage/Epitech/my_script
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Feb 11 16:41:23 2013 maxime ginters
** Last update Wed Feb 27 16:37:53 2013 maxime ginters
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "param_functions.h"
#include "params_parser.h"

t_params_entry	params_tab[] = {
  {'a', parse_a_param, "Append the ouput to file or typescript.\n"},
  {0, NULL, NULL}
};

static void	init_params(t_params* params)
{
  char*	tmp;

  params->append = 0;
  params->file = NULL;
  tmp = getenv("SHELL");
  if (tmp)
    params->shell = strdup(tmp);
  else
    params->shell = strdup("/bin/sh");
}

static void	handle_param(t_params* params, char** av, int i)
{
  int	j;

  j = 0;
  while (params_tab[j].key != 0)
  {
    if (params_tab[j].key == av[i][1])
    {
      (params_tab[j].fct)(params, av, i);
      return;
    }
    ++j;
  }
  printf("Error: unknow param '%s'\n", av[i]);
  exit(1);
}

t_params*	create_params(char** av, int ac)
{
  t_params* params;
  int	i;

  if ((params = malloc(sizeof(t_params))) == NULL)
    return NULL;
  init_params(params);
  i = 1;
  while (i < ac)
  {
    if (av[i][0] == '-')
      handle_param(params, av, i);
    else if (!params->file)
      params->file = strdup(av[i]);
    ++i;
  }
  if (!params->file)
    params->file = strdup("typescript");
  return params;
}

void	clear_params(t_params* params)
{
  if (!params)
    return;

  if (params->file)
    free(params->file);
  if (params->shell)
    free(params->shell);
  free(params);
}

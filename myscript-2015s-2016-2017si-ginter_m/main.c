/*
** main.c for my_script in /Storage/Epitech/my_script
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Feb 11 16:29:14 2013 maxime ginters
** Last update Wed Feb 27 16:21:29 2013 maxime ginters
*/

#include <stdio.h>
#include <stdlib.h>
#include "params_parser.h"
#include "core.h"

int	main(int argc, char **argv)
{
  t_params* params;

  params = create_params(argv, argc);
  run(params);
  clear_params(params);
  return (0);
}

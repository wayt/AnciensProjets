/*
** sum_params.c for ex_03 in /home/ginter_m/Jour_08/ex_03
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 10 11:52:40 2012 maxime ginters
** Last update Wed Oct 10 12:05:22 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

int	get_params_full_size(int ac, char **av)
{
  int	size;
  int	i;

  i = 0;
  size = 0;
  while (i < ac)
  {
    size += my_strlen(av[i++]);
    if (i < ac)
      size += 1;
  }
  return (size);
}

char	*sum_params(int argc, char **argv)
{
  char	*result;
  int	i;

  result = malloc((get_params_full_size(argc, argv) + 1)* sizeof(char));
  i = 0;
  while (i < argc)
  {
    my_strcat(result, argv[i++]);
    if (i < argc)
      my_strcat(result, "\n");
  }
  return result;
}

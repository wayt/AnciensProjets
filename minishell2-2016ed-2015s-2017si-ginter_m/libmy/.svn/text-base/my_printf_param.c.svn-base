/*
** my_printf_param.c for libmy in /home/fest/Epitech/my_printf/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sun Nov 18 14:04:22 2012 maxime ginters
** Last update Sun Nov 18 15:02:23 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

void	init(t_printf_params *par, int *from, int *i)
{
  par->width = 0;
  par->prec = 0;
  *from = 0;
  *i = 0;
}

t_printf_params		*create_printf_params(char *str)
{
  t_printf_params	*params;
  int			from;
  int			i;
  char			*tmp;

  params = xmalloc(sizeof(t_printf_params));
  init(params, &from, &i);
  while (str[i] != '\0')
    if (str[i++] == '.')
    {
      tmp = my_substr(str, from, i - 2);
      params->width = my_getnbr(tmp);
      free(tmp);
      from = i;
    }
  tmp = my_substr(str, from, i - 1);
  if (params->width != 0 || str[0] == '.')
    params->prec = my_getnbr(tmp);
  else
    params->width = my_getnbr(tmp);
  free(tmp);
  free(str);
  return (params);
}

/*
** my_printf.c for libmy in /home/fest/Epitech/my_printf/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Nov 13 11:31:21 2012 maxime ginters
** Last update Sun Nov 18 15:15:50 2012 maxime ginters
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	is_flag(char c)
{
  if (my_isnum(c) == 1)
    return (1);
  if (c == '.')
    return (1);
  return (0);
}

int			do_aff(char* str, int pct_i, int type_i, va_list ap)
{
  int			i;
  t_printf_params	*params;
  int			size;

  params = create_printf_params(my_substr(str, pct_i + 1, type_i - 1));
  i = 0;
  size = -1;
  while (my_printf_funct[i].type != '\0' && size == -1)
  {
    if (my_printf_funct[i].type == str[type_i])
      size = (my_printf_funct[i].funct)(ap, params);
    ++i;
  }
  free(params);
  if (my_printf_funct[i].type == '\0' && size == -1)
  {
    write(1, "%", 1);
    return (1);
  }
  return (size);
}

int	print_between(char *str, int *pct_i, int *i)
{
  int	j;

  j = 0;
  if (*pct_i != -1)
  {
    j = *pct_i;
    while (j <= (*i - 1))
      write(1, str + j++, 1);
    j = *i - *pct_i + 1;
  }
  *pct_i = *i;
  return (j);
}

void	init_printf(int *i, int *size, int *pct_i)
{
  *i = 0;
  *size = 0;
  *pct_i = -1;
}

int		my_printf(char *str, ...)
{
  va_list	ap;
  int		pct_i;
  int		size;
  int		i;

  init_printf(&i, &size, &pct_i);
  va_start(ap, str);
  while (str[i])
  {
    if (pct_i != -1)
    {
      if (is_flag(str[i]) == 0)
      {
        size += do_aff(str, pct_i, i, ap);
        pct_i = -1;
      }
    }
    else if (str[i] == '%')
      size += print_between(str, &pct_i, &i);
    else
      size += my_putchar(str[i]);
    ++i;
  }
  va_end(ap);
  return (size);
}

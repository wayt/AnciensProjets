/*
** my_printf.c for libmy in /home/fest/Epitech/my_printf/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Nov 13 11:31:21 2012 maxime ginters
** Last update Tue Nov 13 16:48:25 2012 maxime ginters
*/

#include <stdarg.h>
#include "my.h"

int	do_aff(char type, va_list ap)
{
  int	i;

  i = 0;
  while (my_printf_funct[i].type != '\0')
  {
    if (my_printf_funct[i].type == type)
      return ((my_printf_funct[i].funct)(ap));
    ++i;
  }
  if (my_printf_funct[i].type == '\0')
  {
    write(1, "%", 1);
    write(1, &type, 1);
    return (2);
  }
  return (0);
}

int		my_printf(char *str, ...)
{
  va_list	ap;
  char		prev;
  int		size;

  size = 0;
  prev = 0;
  va_start(ap, str);
  while (*str)
  {
    if (prev == '%')
      size += do_aff(*str, ap);
    else if (*str != '%' || prev == '%')
    {
      write(1, str, 1);
      ++size;
    }
    prev = *str;
    ++str;
  }
  va_end(ap);
  return (size);
}

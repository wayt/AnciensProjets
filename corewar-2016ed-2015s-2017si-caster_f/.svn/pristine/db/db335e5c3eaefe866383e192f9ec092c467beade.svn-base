/*
** my_printf.c for lib in /home/leroy_v/Epitech/corewar/lib
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Mon Dec 03 14:26:00 2012 vincent leroy
** Last update Mon Dec 03 16:01:36 2012 vincent leroy
*/

#include <stdarg.h>
#include "my.h"

void		my_printf(char *format, ...)
{
  int		i;
  va_list	ap;

  i = 0;
  va_start(ap, format);
  while (format[i] != '\0')
  {
    if (format[i] == '%')
    {
      if (format[i + 1] == 'd')
	my_putnbr(va_arg(ap, int));
      else if (format[i + 1] == 's')
	my_putstr(va_arg(ap, char*));
      else
	write(1, &format[i + 1], 1);
      if (format[i + 1] != '\0')
	i++;
    }
    else
      write(1, &format[i], 1);
    i++;
  }
  va_end(ap);
}

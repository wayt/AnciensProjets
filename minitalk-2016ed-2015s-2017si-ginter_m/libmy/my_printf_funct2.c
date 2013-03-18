/*
** my_printf_funct2.c for libmy in /home/fest/Epitech/my_printf/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Nov 13 13:50:46 2012 maxime ginters
** Last update Wed Nov 14 17:57:55 2012 maxime ginters
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int		print_oct(va_list ap)
{
  uint	d;

  if ((d = (uint)va_arg(ap, int)) == 0)
    return (0);
  return (my_putnbr_base_long(d, "01234567"));
}

int		print_hex(va_list ap)
{
  uint	d;

  if ((d = (uint)va_arg(ap, int)) == 0)
    return (0);
  return (my_putnbr_base_long((ulong)d, "0123456789abcdef"));
}

int		print_hex_up(va_list ap)
{
  uint	d;

  if ((d = (uint)va_arg(ap, int)) == 0)
    return (0);
  return (my_putnbr_base_long(d, "0123456789ABCDEF"));
}

int		print_unsigned(va_list ap)
{
  uint	d;
  char	*s;

  if ((d = (uint)va_arg(ap, int)) == 0)
    return (0);
  s = my_nbr_to_char(d);
  my_putstr(s);
  d = my_strlen(s);
  free(s);
  return ((int)d);
}

int	print_paddress(va_list ap)
{
  ulong	d;

  if ((d = (ulong)va_arg(ap, ulong)) == 0)
    return (0);
  my_putstr("0x");
  return (2 + my_putnbr_base_long(d, "0123456789abcdef"));
}

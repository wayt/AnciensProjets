/*
** my_printf_funct2.c for libmy in /home/fest/Epitech/my_printf/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Nov 13 13:50:46 2012 maxime ginters
** Last update Sun Nov 18 14:56:36 2012 maxime ginters
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int		print_oct(va_list ap, t_printf_params* params)
{
  uint	d;

  if ((d = (uint)va_arg(ap, int)) == 0)
    return (0);
  return (my_putnbr_base_long(d, "01234567"));
}

int		print_hex(va_list ap, t_printf_params* params)
{
  uint	d;

  if ((d = (uint)va_arg(ap, int)) == 0)
    return (0);
  return (my_putnbr_base_long((ulong)d, "0123456789abcdef"));
}

int		print_hex_up(va_list ap, t_printf_params* params)
{
  uint	d;

  if ((d = (uint)va_arg(ap, int)) == 0)
    return (0);
  return (my_putnbr_base_long(d, "0123456789ABCDEF"));
}

int		print_unsigned(va_list ap, t_printf_params* params)
{
  uint	d;
  char	*s;
  int	str_len;

  if ((d = (uint)va_arg(ap, int)) == 0)
    return (0);
  s = my_nbr_to_char(d);
  str_len = my_strlen(s);
  my_put_x_space(params->width - str_len);
  my_putstr(s);
  free(s);
  return (params->width > str_len ? params->width : str_len);
}

int	print_paddress(va_list ap, t_printf_params* params)
{
  ulong	d;

  if ((d = (ulong)va_arg(ap, ulong)) == 0)
    return (0);
  my_putstr("0x");
  return (2 + my_putnbr_base_long(d, "0123456789abcdef"));
}

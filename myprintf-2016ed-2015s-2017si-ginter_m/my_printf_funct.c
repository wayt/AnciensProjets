/*
** my_printf_funct.c for libmy in /home/fest/Epitech/my_printf/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Nov 13 12:01:35 2012 maxime ginters
** Last update Sun Nov 18 14:49:16 2012 maxime ginters
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	print_string(va_list ap, t_printf_params* params)
{
  char	*s;
  int	str_len;

  if ((s = va_arg(ap, char*)) == 0)
    return (0);
  str_len = my_strlen(s);
  my_put_x_space(params->width - str_len);
  my_putstr(s);
  return (params->width > str_len ? params->width : str_len);
}

int	print_int(va_list ap, t_printf_params* params)
{
  int	d;
  char	*s;
  int	str_len;

  if ((d = va_arg(ap, int)) == 0)
    return (0);
  s = my_nbr_to_char(d);
  str_len = my_strlen(s);
  my_put_x_space(params->width - str_len);
  my_putstr(s);
  d = my_strlen(s);
  free(s);
  return (params->width > str_len ? params->width : str_len);
}

int	print_char(va_list ap, t_printf_params* params)
{
  char	c;

  if ((c = (char)va_arg(ap, int)) == 0)
    return (0);
  my_put_x_space(params->width - 1);
  write(1, &c, 1);
  return (params->width > 1 ? params->width : 1);
}

int		print_bin(va_list ap, t_printf_params* params)
{
  unsigned int	d;

  if ((d = va_arg(ap, unsigned int)) == 0)
    return (0);
  return ((int)my_putnbr_base_long((ulong)d, "01"));
}

int	print_string_oct(va_list ap, t_printf_params* params)
{
  char	*s;
  int	size;

  size = 0;
  if ((s = va_arg(ap, char*)) == 0)
    return (0);
  while (*s != '\0')
  {
    if (*s < 32 || *s >= 127)
    {
      write(1, "\\", 1);
      size += 1 + my_putnbr_base_long((ulong)*s, "01234567");
    }
    else
    {
      write(1, s, 1);
      ++size;
    }
    ++s;
  }
  return (size);
}

/*
** my_atof.c for libmy in /home/fest/Epitech/my_printf/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Nov 14 17:44:35 2012 maxime ginters
** Last update Thu Nov 15 18:36:18 2012 maxime ginters
*/

#include "my.h"

double		my_atof(char *str)
{
  double	val;
  int		e;

  e = 0;
  val = 0.0;
  while (*str != '\0' && my_isnum(*str) == 1)
    val = val * 10.0 + (*str++ - '0');
  if (*str == '.')
  {
    while (*str != '\0' && my_isnum(*str) == 1)
    {
      val = val * 10.0 + (*str++ - '0');
      e -= 1;
    }
  }
  while (e++ < 0)
    val *= 0.1;
  return (val);
}

int		my_put_float(double val, uint prec)
{
  char		buffer[64];
  double	tmp;
  uint		i;

  if (prec > 40)
    prec = 40;
  i = 0;
  tmp = val;
  my_memset(buffer, 0x0, 64);
  while ((ulong)tmp > 0)
  {
    buffer[i++] = '0' + ((ulong)tmp % 10);
    tmp /= 10;
  }
  my_revstr(buffer);
  buffer[i++] = '.';
  val *= 10;
  while (prec-- > 0)
  {
    buffer[i++] = '0' + ((ulong)val % 10);
    val *= 10;
  }
  my_putstr(buffer);
  return (my_strlen(buffer));
}

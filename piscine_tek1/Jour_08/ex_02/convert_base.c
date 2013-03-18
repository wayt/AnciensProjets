/*
** convert_base.c for ex_02 in /home/ginter_m/Jour_08/ex_02
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 10 10:13:07 2012 maxime ginters
** Last update Wed Oct 10 11:51:10 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	val;

  val = my_getnbr_base(nbr, base_from);
  return my_putnbr_base_char(val, base_to);
}

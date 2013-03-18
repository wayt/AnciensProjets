/*
** do_op.c for do-op in /home/fest/Epitech/Jour_11/do-op
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 22 20:50:40 2012 maxime ginters
** Last update Tue Oct 23 14:15:31 2012 maxime ginters
*/

#include "my.h"

void	do_op_plus(char *v1, char *v2)
{
  my_put_nbr(my_getnbr(v1) + my_getnbr(v2));
}

void	do_op_moin(char *v1, char *v2)
{
  my_put_nbr(my_getnbr(v1) - my_getnbr(v2));
}

void	do_op_mult(char *v1, char *v2)
{
  my_put_nbr(my_getnbr(v1) * my_getnbr(v2));
}

void	do_op_div(char *v1, char *v2)
{
  int	val;

  val = my_getnbr(v2);
  if (val == 0)
  {
    my_putstr("Stop : division by zero");
    return ;
  }
  my_put_nbr(my_getnbr(v1) / val);
}

void	do_op_mod(char *v1, char *v2)
{
  int	val;

  val = my_getnbr(v2);
  if (val == 0)
  {
    my_putstr("Stop : modulo by zero");
    return ;
  }
  my_put_nbr(my_getnbr(v1) % val);
}

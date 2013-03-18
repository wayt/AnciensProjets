/*
** main.c for eval_expr in /home/fest/Epitech/eval_expr
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 25 16:45:00 2012 maxime ginters
** Last update Thu Oct 25 16:54:41 2012 maxime ginters
*/

#include "my.h"
#include "eval_expr.h"

int	main(int ac, char **av)
{
  if (ac > 1)
  {
    my_put_nbr(eval_expr(av[1]));
    my_putchar('\n');
  }
  return (0);
}

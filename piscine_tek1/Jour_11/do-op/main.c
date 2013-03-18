/*
** main.c for do-op in /home/fest/Epitech/Jour_11/do-op
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 22 22:11:07 2012 maxime ginters
** Last update Tue Oct 23 14:14:22 2012 maxime ginters
*/

#include "my.h"

void	do_op_plus(char *, char *);
void	do_op_moin(char *, char *);
void	do_op_mult(char *, char *);
void	do_op_div(char *, char *);
void	do_op_mod(char *, char *);
int	get_fct_id(char);

int	main(int ac, char **av)
{
  if (ac < 4)
    return (1);

  void	(*functions[5])(char *, char *);
  int	fct;

  functions[0] = do_op_plus;
  functions[1] = do_op_moin;
  functions[2] = do_op_mult;
  functions[3] = do_op_div;
  functions[4] = do_op_mod;
  fct = get_fct_id(av[2][0]);
  if (fct != -1)
    (*functions[fct])(av[1], av[3]);
  my_putchar('\n');
  return (0);
}

int	get_fct_id(char c)
{
  int	fct;

  fct = -1;
  if (c == '+')
    fct = 0;
  else if (c == '-')
    fct = 1;
  else if (c == '*')
    fct = 2;
  else if (c == '/')
    fct = 3;
  else if (c == '%')
    fct = 4;
  return (fct);
}

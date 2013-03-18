/*
** my_aff_params.c for ex_02 in /home/ginter_m/Jour_07/ex_02
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 14:00:14 2012 maxime ginters
** Last update Tue Oct 09 14:06:54 2012 maxime ginters
*/

void	my_putstr(char *);
void	my_putchar(char);

int	main(int ac, char *av[])
{
  int	i;

  i = 0;
  while (i < ac)
  {
    my_putstr(av[i]);
    my_putchar('\n');
    ++i;
  }

  return (0);
}

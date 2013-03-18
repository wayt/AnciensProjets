/*
** my_rev_params.c for ex_03 in /home/ginter_m/Jour_07/ex_03
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 14:04:05 2012 maxime ginters
** Last update Tue Oct 09 14:06:33 2012 maxime ginters
*/

void	my_putstr(char *);
void	my_putchar(char);

int	main(int ac, char *av[])
{
  int	i;

  i = ac - 1;
  while (i >= 0)
  {
    my_putstr(av[i]);
    my_putchar('\n');
    --i;
  }
  return (0);
}

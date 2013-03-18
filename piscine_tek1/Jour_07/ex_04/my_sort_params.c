/*
** my_sort_params.c for ex_04 in /home/ginter_m/Jour_07/ex_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Oct 09 14:12:42 2012 maxime ginters
** Last update Tue Oct 09 14:20:47 2012 maxime ginters
*/

int	strcmp(char *, char *);
void	my_putstr(char *);
void	my_putchar(char);

void	my_sort_params(char **tab, int size)
{
  char	*temp;
  int	i;
  int	j;

  i = 0;
  while (i < size)
  {
    j = 0;
    while (j < size)
    {
      if (my_strcmp(tab[i], tab[j]) < 0)
      {
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
      }
      ++j;
    }
    ++i;
  }
}

int	main(int ac, char *av[])
{
  my_sort_params(av, ac);

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

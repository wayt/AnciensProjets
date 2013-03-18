/*
** colle1-2.c for colle1-2 in /home/nguy_v//afs/rendu/piscine/colles/Semaine_01
** 
** Made by virgil nguyen
** Login   <nguy_v@epitech.net>
** 
** Started on  Sat Oct 29 21:31:31 2011 virgil nguyen
** Last update Sat Oct 27 19:47:50 2012 maxime ginters
*/

void	my_display(int x, int y, int row, int col)
{
  if (x == 1 || y == 1)
    my_putchar('o');
  else if ((row == x - 1 || row == 0) && (col == 0 || col == y - 1))
    my_putchar('o');
  else if (row == 0 || row == x - 1)
    my_putchar('-');
  else if (col == 0 || col == y - 1)
    my_putchar('|');
  else
    my_putchar(' ');
}

int	colle(int x, int y)
{
  int	i;
  int	j;

  j = 0;
  while (j < x && x > 0)
    {
      i = 0;
      while (i < y)
	{
	  my_display(x, y, j, i);
	  i++;
	}
      my_putchar('\n');
      j++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  colle(my_getnbr(av[1]), my_getnbr(av[2]));
  return (0);
}

/*
** colle1-1.c for colle in /home/nguy_v//afs/rendu/piscine/colles/Semaine_01
** 
** Made by virgil nguyen
** Login   <nguy_v@epitech.net>
** 
** Started on  Sat Oct  6 13:52:01 2012 virgil nguyen
** Last update Sat Oct  6 13:53:12 2012 virgil nguyen
*/

void	my_display(int x, int y, int i, int j)
{
  if (x == 1 || y == 1)
    my_putchar('*');
  else if ((j == 0 && i == 0) || (j == (y - 1) && i == (x - 1)))
    my_putchar('/');
  else if ((j == 0 && i == (x - 1)) || (j == (y - 1) && i == 0))
    my_putchar('\\');
  else if (((j == 0 || j == (y - 1)) && (i > 0 && i < (x - 1))))
    my_putchar('*');
  else if ((j > 0 && j < (y - 1)) && (i == 0 || i == (x - 1)))
    my_putchar('*');
  else
    my_putchar(' ');
}

void	colle(int x, int y)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (j < y)
    {
      i = 0;
      while (i < x)
	{
	  my_display(x, y, i, j);
	  i++;
	}
      my_putchar('\n');
      j++;
    }
}

int     main(int ac, char **av)
{
  colle(my_getnbr(av[1]), my_getnbr(av[2]));
  return (0);
}

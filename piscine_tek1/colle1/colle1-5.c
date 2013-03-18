/*
** colle1-5.c for colle1 in /home/ginter_m/colle1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Oct 06 12:40:35 2012 maxime ginters
** Last update Sat Oct 06 13:40:56 2012 maxime ginters
*/

void	my_display(int x, int y, int row, int col)
{
  if (x == 1 || y == 1)
    my_putchar('B');
  else if ((row == 0 || row == x - 1) && col != 0 && col != y - 1)
    my_putchar('B');
  else if ((col == 0 || col == y - 1) && row != 0 && row != x - 1)
    my_putchar('B');
  else if ((row == 0 && col == 0) || (row == x - 1 && col == y - 1))
    my_putchar('A');
  else if ((row == 0 && col == y - 1) || (row == x - 1 && col == 0))
    my_putchar('C');
  else
    my_putchar(' ');
}

int	colle(int x, int y)
{
  int	row;
  int	col;

  if (x == 0 || y == 0)
    return 0;

  row = 0;
  while (row < x)
  {
    col = 0;
    while (col < y)
    {
      my_display(x, y, row, col);
      ++col;
    }
    my_putchar('\n');
    ++row;
  }
}

int	main(int argc, char *argv[])
{
  if (argc < 3)
    return 0;

  colle(my_getnbr(argv[1]), my_getnbr(argv[2]));
  return 0;
}

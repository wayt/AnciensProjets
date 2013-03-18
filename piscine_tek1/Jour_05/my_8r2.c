/*
** my_8r2.c for Jour_05 in /home/ginter_m/Jour_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 05 15:06:22 2012 maxime ginters
** Last update Fri Oct 05 15:18:22 2012 maxime ginters
*/

int	my_abs2(int n)
{
  return n < 0 ? -n : n;
}

int	est_libre2(int *tab, int rang, int col)
{
  int	r;

  r = 0;
  while (r < rang)
  {
    if (!(my_abs2(rang - r) != my_abs2(col - tab[r]) && col != tab[r]))
      return 0;
    ++r;
  }
  return 1;
}

void	print_result(int *tab)
{
  int	i;

  i = 0;
  while (i < 8)
    my_putchar('0' + tab[i++]);
  my_putchar('\n');
}

int	placer_reine2(int *tab, int reine)
{
  int	col;
  int	total;

  total = 0;
  if (reine >= 8)
  {
    print_result(tab);
    return 1;
  }
  else
  {
    col = 0;
    while (col < 8)
    {
      if (est_libre2(tab, reine, col) == 1)
      {
        tab[reine] = col;
        total += placer_reine2(tab, reine + 1);
        tab[reine] = 0;
      }
      ++col;
    }
  }
  return total;
}

int	my_8r2()
{
  int	tab[8];
  int	i;

  i = 0;
  while (i < 8)
    tab[++i] = 0;

  return placer_reine2(tab, 0);
}

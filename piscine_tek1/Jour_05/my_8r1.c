/*
** my_8r1.c for Jour_05 in /home/ginter_m/Jour_05
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Fri Oct 05 12:57:02 2012 maxime ginters
** Last update Fri Oct 05 15:09:45 2012 maxime ginters
*/

int	my_abs(int n)
{
  return n < 0 ? -n : n;
}

int	est_libre(int *tab, int rang, int col)
{
  int	r;

  r = 0;
  while (r < rang)
  {
    if (!(my_abs(rang - r) != my_abs(col - tab[r]) && col != tab[r]))
      return 0;
    ++r;
  }
  return 1;
}

int	placer_reine(int *tab, int reine)
{
  int	col;
  int	total;

  total = 0;
  if (reine >= 8)
    return 1;
  else
  {
    col = 0;
    while (col < 8)
    {
      if (est_libre(tab, reine, col) == 1)
      {
        tab[reine] = col;
        total += placer_reine(tab, reine + 1);
        tab[reine] = 0;
      }
      ++col;
    }
  }
  return total;
}

void	init_tab(int *tab)
{
  int	i;

  i = 0;
  while (i < 8)
    tab[i++] = 0;
}

int	my_8r1()
{
  int	tab[8];

  init_tab(tab);

  return placer_reine(tab, 0);
}

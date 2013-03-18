/*
** my_sort_int_tab.c for Jour_04 in /home/ginter_m/Jour_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Oct 04 10:26:29 2012 maxime ginters
** Last update Tue Oct 09 10:24:49 2012 maxime ginters
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	changed;
  int	i;

  changed = 1;
  i = 0;
  while (changed == 1)
  {
    changed = 0;
    i = 0;
    while (i < size - 1)
    {
      if (*(tab + i) > *(tab + i + 1))
      {
        my_swap(tab + i, tab + i + 1);
        changed = 1;
      }
      ++i;
    }
  }
}


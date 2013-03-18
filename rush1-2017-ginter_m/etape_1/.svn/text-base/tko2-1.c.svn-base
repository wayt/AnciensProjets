/*
** tko2-1.c for  in /home/sivado_a//Documents/rendus/rush1-2017-ginter_m/etape_1
** 
** Made by alexandre sivadon
** Login   <sivado_a@epitech.net>
** 
** Started on  Fri Nov 30 20:21:32 2012 alexandre sivadon
** Last update Fri Nov 30 22:54:58 2012 alexandre sivadon
*/

#include <stdio.h>
#include <stdlib.h>
#include "create_tab.h"
#include "tko2-1.h"

int	main(int ac, char **av)
{
  int	i;
  int	j;
  char	**tab;
  char	**tab2;

  if (ac != 3)
    {
      printf("Erreur: Veuillez entrer 2 arguments\n");
      exit(1);
    }
  i = 0;
  j = 0;
  tab = create_tab(av[1]);
  tab2 = create_tab(av[2]);
  while (tab[i] || tab2[j])
    {
      if (tab[i] && tab2[j])
	printf("%s_%s\n", tab[i++], tab2[j++]);
      else if (tab[i] && tab2[j] == NULL)
	printf("%s\n", tab[i++]);
      else if ((tab[i] == NULL) && tab2[j])
	printf("%s\n", tab2[j++]);
    }
  return (0);
}

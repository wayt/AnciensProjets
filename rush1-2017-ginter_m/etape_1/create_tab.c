/*
** create_tab.c for etape_1 in /home/fest/Epitech/rush1-2017-ginter_m/etape_1
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Nov 30 20:24:44 2012 maxime ginters
** Last update Fri Nov 30 23:38:41 2012 maxime ginters
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create_tab.h"

char	**create_tab(char *file)
{
  FILE	*fp;
  size_t	len;
  int	read;
  char	**tab;
  char	*buff;
  int	i;

  if ((tab = malloc(1 * sizeof(char*))) == 0)
      return (NULL);
  fp = fopen(file, "r");
  if (fp == NULL)
    return (NULL);
  i = -1;
  buff = NULL;
  while ((read = getline(&buff, &len, fp)) != -1)
    if (i++ >= 0)
    {
      buff[read - 1] = '\0';
      tab[i - 1] = strdup(buff);
      tab = realloc(tab, (i + 1) * sizeof(char*));
    }
  fclose(fp);
  return (tab);
}

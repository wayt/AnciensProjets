/*
** play.c for etape_3 in /home/fest/Epitech/rush1-2017-ginter_m/etape_3
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Dec 01 02:39:12 2012 maxime ginters
** Last update Sat Dec 01 23:11:15 2012 maxime ginters
*/

#define _GNU_SOURCE
#include <string.h>
#include "commandes_parser.h"
#include "create_platine.h"
#include "functions.h"
#include "play.h"
#include "fx.h"

char	*revstr(char *str)
{
  int	i;
  int	j;
  char	tmp;

  i = 0;
  j = strlen(str) - 1;
  while (i < j)
  {
    tmp = str[i];
    str[i++] = str[j];
    str[j--] = tmp;
  }
  return (str);
}

char	*remove_cut(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    if (str[i] == ':')
    {
        str[i] = '\0';
        return (str);
    }
  return (str);
}

char	*play(t_platine *p)
{
  char	*str;
  if (p->cmd[p->index][0] == '#')
    str = strdup("shrrrck");
  else
    str = remove_cut(strdup(p->cmd[p->index]));
  if (p->lowpass == 1)
    str = filter_lowpass(str);
  if (p->highpass == 1)
    str = filter_highpass(str);
  if (p->doubl == 1)
    str = fx_double(str);
  if (p->flanger == 1)
    str = flanger(str);
  if (p->echo == 1)
    str = fx_echo(str);
  reset_all_fx(p);
  if (p->reversed == 1)
    return (revstr(str));
  return (str);
}

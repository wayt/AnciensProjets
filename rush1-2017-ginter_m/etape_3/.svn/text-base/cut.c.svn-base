/*
** cut.c for etape_3 in /home/fest/Epitech/rush1-2017-ginter_m/etape_3
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Dec 01 04:20:26 2012 maxime ginters
** Last update Sat Dec 01 17:14:48 2012 maxime ginters
*/

#include <stdio.h>
#include "create_platine.h"
#include "commandes_parser.h"
#include "functions.h"

void	handle_cut(t_platine *pa, t_platine *pb, t_command* cmd)
{
  (void)cmd;
  if (pa->active != pb->active)
  {
    pa->active = !pa->active;
    pb->active = !pb->active;
  }
}



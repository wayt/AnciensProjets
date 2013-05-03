/*
** ichans.h for myirc in /home/vaga/Projects/tek2/myirc/src_client/ncurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Apr 26 16:34:35 2013 fabien casters
** Last update Sat Apr 27 18:06:13 2013 fabien casters
*/

#ifndef ICHANS_H_
# define ICHANS_H_

#include "list.h"
#include "interface.h"
#include "channels.h"

void refresh_chans(t_interface *in, t_list list, t_channel *current);

#endif


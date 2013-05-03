/*
** interface.h for myirc in /home/vaga/Projects/tek2/myirc/src_client/ncurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Apr 26 14:11:58 2013 fabien casters
** Last update Sun Apr 28 16:21:46 2013 fabien casters
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_

#include "window.h"

#define WIN(w) in->w.win

struct		s_interface
{
  t_window	w_root;
  t_window	w_users;
  t_window	w_chans;
  t_window	w_mesgs;
  t_window	w_input;
};
typedef struct s_interface t_interface;

int		create_interface(t_interface *);
void		refresh_interface(t_interface *);
int		destroy_interface(t_interface *);
int		input_interface(t_interface *in, char *);

int		key_delete(char *buf, int *index, t_interface *in);
int		key_send(char *buf, char *dst, int *index, t_interface *in);
int		key_insert(char *buf, int key, int *index, t_interface *in);

#endif

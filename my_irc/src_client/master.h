/*
** master.h for src_client in /home/fest/Epitech/my_irc/src_client
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 25 15:04:31 2013 maxime ginters
** Last update Sun Apr 28 18:50:48 2013 maxime ginters
*/

#ifndef MASTER_H_
# define MASTER_H_

#include "list.h"
#include "channels.h"
#include "server.h"
#include "interface.h"
#include "ichans.h"
#include "iusers.h"
#include "imesgs.h"

extern t_list		server_list;
extern t_interface	interface;
extern bool		running;
extern t_channel	*accueil;

int	run();
t_server	*get_current_server();
t_channel	*get_current_channel();
int		get_currents_index(int *srv, int *chn);
int		init_fd(fd_set *fds);
void		handle_write();
void		handle_input(t_server *server);

#endif /* !MASTER_H_ */

/*
** client.h for Server in /home/fest/Epitech/Minitalk/Server
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 17 14:59:52 2012 maxime ginters
** Last update Sun Nov 18 12:48:00 2012 maxime ginters
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include "my.h"

typedef struct s_client
{
  int	from_pid;
  char	*str;
  int	str_i;
  int	byte_i;
  struct s_client	*next;
} t_client;

void		remove_client(int pid);
t_client	*add_client(int pid);
t_client	*find_client(int pid);
int		count_client();

extern t_client	*client_list;

#endif /* !CLIENT_H_ */

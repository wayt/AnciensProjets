/*
** client.c for Client in /home/fest/Epitech/Minitalk/Client
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Nov 12 14:11:45 2012 maxime ginters
** Last update Sat Nov 17 14:55:33 2012 maxime ginters
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

typedef struct	s_to_send
{
  int	to_pid;
  char	*str;
  int	str_len;
  int	char_i;
  int	byte_i;
  char	ended;
} t_to_send;

t_to_send	send_queue;

void	send_next()
{
  char	c;
  int	sig;

  c = send_queue.str[send_queue.char_i];
  sig = (c & (1 << send_queue.byte_i++)) ? SIGUSR2 : SIGUSR1;
  kill(send_queue.to_pid, sig);
  if (send_queue.byte_i >= 8)
  {
    my_putstr(".");
    send_queue.byte_i = 0;
    if (++send_queue.char_i > send_queue.str_len)
      send_queue.ended = 1;
  }
}

void	handle_signal(int num, siginfo_t *info, void *nul)
{
  if (num != SIGUSR1 ||info->si_pid != send_queue.to_pid)
    return;
  if (send_queue.ended == 1)
    return;
  send_next();
}

void	exit_error(char *str)
{
  my_putstr(str);
  exit(1);
}

int	main(int ac, char **av)
{
  struct sigaction	*act;

  if (ac < 3)
    exit_error("Usage : ./client [server pid] \"[message]\"\n");
  send_queue.to_pid = my_getnbr(av[1]);
  if (send_queue.to_pid <= 0)
    exit_error("Error : invalide pid\n");
  send_queue.str_len = my_strlen(av[2]);
  send_queue.str = av[2];
  send_queue.char_i = 0;
  send_queue.byte_i = 0;
  send_queue.ended = 0;
  act = xmalloc(sizeof(struct sigaction));
  act->sa_handler = NULL;
  act->sa_sigaction = handle_signal;
  sigemptyset(&act->sa_mask);
  act->sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, act, NULL);
  send_next();
  while (send_queue.ended == 0)
    usleep(1000);
  my_putstr("\n");
  return (0);
}

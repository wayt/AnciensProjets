/*
** server.c for Server in /home/fest/Epitech/Minitalk/Server
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Nov 12 11:46:26 2012 maxime ginters
** Last update Sun Nov 18 12:47:37 2012 maxime ginters
*/

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "client.h"

#define CHAR_S sizeof(char)

t_client	*client_list;

void	print_and_delete_client(t_client *cli)
{
  my_printf("from pid : %d - %s\n\n", cli->from_pid, cli->str);
  remove_client(cli->from_pid);

}

void	print_error(char *str)
{
  my_putstr(str);
  exit(1);
}

void		handle_signal(int num, siginfo_t *info, void *nul)
{
  t_client	*cli;

  cli = find_client(info->si_pid);
  if (cli == NULL)
    cli = add_client(info->si_pid);
  cli->str[cli->str_i] |= (num == SIGUSR2) << cli->byte_i++;
  if (cli->byte_i > 7)
  {
    if (cli->str[cli->str_i] < 0)
      print_error("Transmission error ...\n");
    if (cli->str[cli->str_i] == '\0')
      print_and_delete_client(cli);
    else
    {
      cli->byte_i = 0;
      cli->str_i++;
      cli->str = my_realloc(cli->str, cli->str_i + 1, CHAR_S, cli->str_i);
      cli->str[cli->str_i] = '\0';
    }
  }
  kill(info->si_pid, SIGUSR1);
}

void		handle_signal_mono(int num, siginfo_t *info, void *nul)
{
  t_client	*cli;

  cli = find_client(info->si_pid);
  if (cli == NULL && count_client() > 0)
    return;
  else if (cli == NULL)
    cli = add_client(info->si_pid);
  cli->str[cli->str_i] |= (num == SIGUSR2) << cli->byte_i++;
  if (cli->byte_i > 7)
  {
    if (cli->str[cli->str_i] == '\0')
    {
      my_putstr(cli->str);
      remove_client(info->si_pid);
    }
    else
    {
      cli->byte_i = 0;
      cli->str_i++;
      cli->str = my_realloc(cli->str, cli->str_i + 1, CHAR_S, cli->str_i);
      cli->str[cli->str_i] = '\0';
    }
  }
  kill(info->si_pid, SIGUSR1);
}

int		      	main(int ac, char **av)
{
  struct sigaction	*act;

  act = xmalloc(sizeof(struct sigaction));
  my_put_nbr((int)getpid());
  my_putstr("\n");
  client_list = NULL;
  act->sa_handler = NULL;
  if (ac >= 2 && my_strcmp(av[1], "-multi") == 0)
    act->sa_sigaction = handle_signal;
  else
    act->sa_sigaction = handle_signal_mono;
  sigemptyset(&act->sa_mask);
  act->sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, act, NULL);
  sigaction(SIGUSR2, act, NULL);
  while (1 == 1)
    usleep(10);
  free(act);
  return (0);
}

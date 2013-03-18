/*
** core.c for my_script in /Storage/Epitech/my_script
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Feb 11 17:49:15 2013 maxime ginters
** Last update Fri Mar 08 21:01:09 2013 maxime ginters
*/

#include "core.h"

void	read_input(pid_t ptyfk, pid_t master, int fd)
{
  fd_set	fd_in;
  char	buff[512];
  int	rd_size;

  while (waitpid(ptyfk, NULL, WNOHANG) == 0)
  {
    FD_ZERO(&fd_in);
    FD_SET(0, &fd_in);
    FD_SET(master, &fd_in);
    select(master + 1, &fd_in, NULL, NULL, NULL);
    if (FD_ISSET(0, &fd_in))
    {
      rd_size = read(0, buff, 511);
    write(master, buff, rd_size);
    }
    if (FD_ISSET(master, &fd_in))
    {
      rd_size = read(master, buff, 511);
      write(1, buff, rd_size);
      write(fd, buff, rd_size);
    }
  }
}

void	update_win_size(int fd)
{
  struct winsize	win;
  int	term;
  static int _fd = 0;

  if (fd != 0)
    _fd = fd;
  if ((term = open("/dev/tty", O_RDONLY | O_NONBLOCK)) < 0)
    xperror();
  if (ioctl(term, TIOCGWINSZ, &win) == -1)
    xperror();
  if (ioctl(_fd, TIOCSWINSZ, &win) == -1)
    xperror();
}

void	handle_resize(int num)
{
  (void)num;
  update_win_size(0);
  signal(SIGWINCH, handle_resize);
}

void	dup2_fd(int fd)
{
  dup2(fd, 0);
  dup2(fd, 1);
  dup2(fd, 2);
}

void	run(t_params const* params)
{
  int	fd;
  pid_t	master;
  pid_t	ptyfk;
  struct termios	term;

  fd = open(params->file, O_WRONLY | O_CREAT |
      (params->append == 1 ? O_APPEND : O_TRUNC), 0644);
  if (fd == -1)
      xperror();
  ptyfk = my_forkpty(&master, NULL);
  if (ptyfk == -1)
    xperror();
  if (ptyfk == 0)
  {
    dup2_fd(master);
    execl(params->shell, params->shell, NULL);
    exit(0);
  }
  update_win_size(master);
  signal(SIGWINCH, handle_resize);
  remove_block(master, 0);
  init_term(&term);
  printf("Script started, file is %s\n", params->file);
  read_input(ptyfk, master, fd);
  restore_term(&term);
  close(fd);
  printf("Script done, file is %s\n", params->file);
}

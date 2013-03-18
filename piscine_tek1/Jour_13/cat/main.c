/*
** main.c for Jour_13 in /home/fest/Epitech/Jour_13
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 24 13:44:24 2012 maxime ginters
** Last update Thu Oct 25 18:44:15 2012 maxime ginters
*/

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"

#define BUFFER_SIZE 25000

int	cat_files(int, char **);
int	read_stdin();
int	read_file(char *);
void	print_error(int, char *);
void	my_super_putstr(char *, int);

int	main(int ac, char **av)
{
  if (ac > 1 || ac)
    cat_files(ac, av);
  else
    read_stdin();
  return (0);
}

void	print_error(int err, char *file)
{
  if (err != 2 && err != 13)
    return ;
  my_putstr("cat: ");
  my_putstr(file);
  if (err == 2)
    my_putstr(": No such file or directory");
  else if (err == 13)
    my_putstr(": Persmission denied");
}

int	read_file(char *file)
{
  int	fileid;
  char	buff[BUFFER_SIZE];
  int	count;

  if (my_strcmp(file, "-") == 0)
    return (read_stdin());
  my_memset(buff, 0x0, BUFFER_SIZE);
  fileid = open(file, O_RDONLY);
  if (fileid < 0)
  {
    print_error(errno, file);
    my_putchar('\n');
    return (-1);
  }
  while (count = read(fileid, buff, BUFFER_SIZE))
  {
    my_super_putstr(buff, count);
    my_memset(buff, 0x0, BUFFER_SIZE);
  }
  return (close(fileid));

}
int	cat_files(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
  {
   read_file(av[i]);
   ++i;
  }
}

int	read_stdin()
{
  char	buff[BUFFER_SIZE];

  my_memset(buff, 0x0, BUFFER_SIZE);
  while (read(0, buff, BUFFER_SIZE))
  {
    my_putstr(buff);
    my_memset(buff, 0x0, BUFFER_SIZE);
  }
  return (0);
}

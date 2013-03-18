/*
** my_files_detailed.c for tp_fs in /home/fest/Epitech/tp_fs
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Oct 29 14:22:50 2012 maxime ginters
** Last update Mon Oct 29 17:12:22 2012 maxime ginters
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include "my.h"

#ifndef NULL
  #define NULL 0x0
#endif

char	*get_file_rwx(struct stat *);

void	my_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}

void	my_putstr_no_nl(char *str)
{
  while (*str && *str != '\n')
    write(1, str++, 1);
}

void	put_formated_time(char *str)
{
  int	i;

  i = 4;
  while (i < 16)
    write(1, &str[i++], 1);
}

void	print_stat(struct stat *st, char *name)
{
  struct passwd	*pwd;
  struct group	*grp;
  char	*buff;

  buff = get_file_rwx(st);
  my_putstr(buff);
  free(buff);
  my_putstr(" ");
  my_put_nbr(st->st_nlink);
  my_putstr(" ");
  if ((pwd = getpwuid(st->st_uid)) != NULL)
    my_putstr(pwd->pw_name);
  my_putstr(" ");
  if ((grp = getgrgid(st->st_gid)) != NULL)
    my_putstr(grp->gr_name);
  my_putstr(" ");
  my_put_nbr(st->st_size);
  my_putstr(" ");
  put_formated_time(ctime(&st->st_mtime));
  my_putstr(" ");
  my_putstr(name);
}

char	get_file_type(struct stat *st)
{
  if (S_ISDIR(st->st_mode))
    return ('d');
  else if (S_ISLNK(st->st_mode))
    return ('l');
  else if (S_ISBLK(st->st_mode))
    return ('b');
  else if (S_ISCHR(st->st_mode))
    return ('c');
  else if (S_ISFIFO(st->st_mode))
    return ('p');
  else if (S_ISSOCK(st->st_mode))
    return ('s');
  return ('-');
}

char	*get_file_rwx(struct stat *st)
{
  char	*buff;

  buff = malloc(11 * sizeof(char));
  my_memset(buff, '-', 11);
  buff[10] = '\0';
  buff[0] = get_file_type(st);
  if (st->st_mode & S_IRUSR)
    buff[1] = 'r';
  if (st->st_mode & S_IWUSR)
    buff[2] = 'w';
  if (st->st_mode & S_IXUSR)
    buff[3] = 'x';
  if (st->st_mode & S_IRGRP)
    buff[4] = 'r';
  if (st->st_mode & S_IWGRP)
    buff[5] = 'w';
  if (st->st_mode & S_IXGRP)
    buff[6] = 'x';
  if (st->st_mode & S_IROTH)
    buff[7] = 'r';
  if (st->st_mode & S_IWOTH)
    buff[8] = 'w';
  if (st->st_mode & S_IXOTH)
    buff[9] = 'x';

  return (buff);
}

int	main(int ac, char **av)
{
  struct dirent	*drt;
  DIR	*dirid;
  struct stat	st;

  dirid = opendir(".");
  if (dirid != NULL)
  {
    while ((drt = readdir(dirid)) > 0)
    {
      if (!(lstat(drt->d_name, &st) < 0))
      {
        print_stat(&st, drt->d_name);
        my_putstr("\n");
      }
    }
  }
}

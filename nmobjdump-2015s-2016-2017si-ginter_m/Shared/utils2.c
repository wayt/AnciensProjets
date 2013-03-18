/*
** utils2.c for Shared in /Storage/Epitech/nm-objdump/Shared
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Mar 17 17:07:14 2013 maxime ginters
** Last update Sun Mar 17 17:11:30 2013 maxime ginters
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

int	fsize(int fd)
{
  lseek(fd, 0, SEEK_SET);
  return (lseek(fd, 0, SEEK_END));
}

void	check_elf_file(int fd)
{
  char	buff[4];

  lseek(fd, 0, SEEK_SET);
  if (read(fd, buff, 4) != 4)
    return;
  if (buff[0] != 0x7f && buff[1] != 'E' && buff[2] != 'L' && buff[3] != 'F')
  {
    printf("Error: invalide file, no elf format\n");
    exit(1);
  }
}

void	throw_corrupted_file()
{
  printf("Corrupted file ...\n");
  exit(1);
}

void	check_plateform(void *data)
{
  if (((char*)data)[4] != 1 && ((char*)data)[4] != 2)
  {
    printf("Error: unknow plateform\n");
    exit(1);
  }
}


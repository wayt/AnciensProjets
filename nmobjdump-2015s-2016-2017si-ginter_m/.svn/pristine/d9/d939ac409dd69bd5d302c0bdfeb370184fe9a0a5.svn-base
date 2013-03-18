/*
** utils.c for Shared in /Storage/Epitech/nm-objdump/Shared
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Mar 12 14:34:05 2013 maxime ginters
** Last update Sun Mar 17 17:22:56 2013 maxime ginters
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

void	set_sym_offset(Elf_data* data)
{
  int	i;

  i = 0;
  data->symtab_offset = -1;
  data->strtab_offset = -1;
  while (i < E_SHNUM(data))
  {
    if (SH_OFFSET(data, E_SHSTRNDX(data)) + SH_NAME(data, i) >= data->fsize)
      throw_corrupted_file();
    if (strcmp(".symtab", &data->strtab[SH_NAME(data, i)]) == 0)
      data->symtab_offset = i;
    if (strcmp(".strtab", &data->strtab[SH_NAME(data, i)]) == 0)
      data->strtab_offset = i;
    ++i;
  }
  if (data->symtab_offset == -1 || data->strtab_offset == -1)
  {
    printf("Error: no symbole table ....");
    exit(1);
  }
}
;
Elf_data	*create_structure(const char* filename)
{
  Elf_data	*data;
  int		fd;

  if ((data = malloc(sizeof(Elf_data))) == 0)
    return (NULL);
  fd = open(filename, O_RDONLY);
  if (fd == -1)
    return (NULL);
  check_elf_file(fd);
  data->filename = filename;
  data->fsize = fsize(fd);
  data->data = mmap(NULL, data->fsize, PROT_READ, MAP_SHARED, fd, 0);
  close(fd);
  if (data->data == MAP_FAILED)
    return (NULL);
  return (data);
}

Elf_data*	create_elf_data(const char* filename)
{
  Elf_data*	data;

  if ((data = create_structure(filename)) == NULL)
    return (NULL);
  check_plateform(data->data);
  data->plateform = (((char*)data->data)[4] == 1 ?
      PLATEFORM_32 : PLATEFORM_64);
  data->elf32 = (Elf32_Ehdr*)data->data;
  data->elf64 = (Elf64_Ehdr*)data->data;
  if (E_SHOFF(data) >= data->fsize)
    throw_corrupted_file();
  data->shdr32 = (Elf32_Shdr*)SHHDR(data);
  data->shdr64 = (Elf64_Shdr*)SHHDR(data);
  data->strtab = (char*)STRTAB(data);
  set_sym_offset(data);
  if (SH_OFFSET(data, data->symtab_offset) >= data->fsize)
    throw_corrupted_file();
  data->symtab32 = (data->data + SH_OFFSET(data, data->symtab_offset));
  data->symtab64 = (data->data + SH_OFFSET(data, data->symtab_offset));
  return (data);
}

void	clean_elf_data(Elf_data* data)
{
  munmap(data->data, data->fsize);
  free(data);
}

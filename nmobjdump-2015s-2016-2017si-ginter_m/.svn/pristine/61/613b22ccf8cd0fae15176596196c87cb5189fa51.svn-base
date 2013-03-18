/*
** objdump.c for objdump in /Storage/Epitech/nm-objdump/objdump
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Mar 12 14:33:14 2013 maxime ginters
** Last update Sun Mar 17 17:28:10 2013 maxime ginters
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "objdump.h"

#define UCHAR(a) (((unsigned char*)a))

void		print_char(unsigned char* ptr, int from, int to)
{
  unsigned char	c;
  int		i;

  if (!(to % 16 == 0))
  {
    i = to;
    while (i < to - (to % 16) + 16)
    {
      printf("  ");
      ++i;
      if (i % 4 == 0 && i % 16 != 0)
        printf(" ");
    }
  }
  printf("\t");
  while (from < to)
  {
    c = *(ptr + from);
    if (c >= 20 && c < 127)
      printf("%c", c);
    else
      printf(".");
    ++from;
  }
}

void	print_section(Elf_data* data, int i)
{
  unsigned int	j;

  while (++i < E_SHNUM(data))
    if (SH_SIZE(data, i) > 0)
    {
      printf("Contents of section %s:\n", &data->strtab[SH_NAME(data, i)]);
      j = 0;
      while (j < SH_SIZE(data, i) && SH_OFFSET(data, i) + j < data->fsize)
      {
        if (j == 0)
          printf(" %04x\t", (unsigned int)SH_ADDR(data, i) + j);
        printf("%02x", *(UCHAR(data->data) + SH_OFFSET(data, i) + j));
        ++j;
        if (j != 0 && j % 16 == 0)
        {
          print_char(UCHAR(data->data) + SH_OFFSET(data, i), j - 16, j);
          printf("\n %04x\t", (unsigned int)SH_ADDR(data, i) + j);
        }
        else if (j != 0 && j % 4 == 0)
          printf(" ");
      }
      print_char(UCHAR(data->data) + SH_OFFSET(data, i), j - (j % 16), j);
      printf("\n");
    }
}

void	print_header(Elf_data* data)
{
  printf("\n%s:\tfile format %s\n", data->filename,
      (IS_64(data) ? "elf64-x86-64" : "elf32-i386"));
  if (E_MACHINE(data) == EM_X86_64 || E_MACHINE(data) == EM_386)
    printf("architecture: %s",
        (E_MACHINE(data) == EM_X86_64 ? "x86-64" : "i386"));
  else
    printf("architecture: %d", (E_MACHINE(data)));
  printf(" flags 0x%x:\n", E_FLAGS(data));
  printf("start address %p\n\n", (void*)E_ENTRY(data));
}

int		dump_obj(const char* filename)
{
  Elf_data	*data;

  if ((data = create_elf_data(filename)) == 0)
  {
    printf("Error: %s\n", strerror(errno));
    return (-1);
  }
  print_header(data);
  print_section(data, -1);
  clean_elf_data(data);
  return (0);
}

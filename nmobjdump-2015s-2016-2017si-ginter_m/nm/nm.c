/*
** nm.c for nm in /Storage/Epitech/nm-objdump/nm
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Mar 13 17:37:57 2013 maxime ginters
** Last update Sun Mar 17 17:32:01 2013 maxime ginters
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nm.h"

char	sub_get_symbol_char(Elf_data* data, int i)
{
  if (SH_TYPE(data, ST_SHNDX(data, i)) == SHT_NOBITS
      && SH_FLAGS(data, ST_SHNDX(data, i)) == (SHF_ALLOC | SHF_WRITE))
    return ('B');
  else if (SH_TYPE(data, ST_SHNDX(data, i)) == SHT_PROGBITS
      && SH_FLAGS(data, ST_SHNDX(data, i)) == SHF_ALLOC)
    return ('R');
  else if (SH_TYPE(data, ST_SHNDX(data, i)) == SHT_PROGBITS
      && SH_FLAGS(data, ST_SHNDX(data, i)) == (SHF_ALLOC | SHF_WRITE))
    return ('D');
  else if (SH_TYPE(data, ST_SHNDX(data, i)) == SHT_PROGBITS
      && SH_FLAGS(data, ST_SHNDX(data, i)) == (SHF_ALLOC | SHF_EXECINSTR))
    return ('T');
  else if (SH_TYPE(data, ST_SHNDX(data, i)) == SHT_DYNAMIC)
    return ('D');
  return ('?');
}

char	get_symbol_char(Elf_data* data, int i)
{
  if (ST_INFO_BIND(data, i) == STB_GNU_UNIQUE)
    return ('u');
  else if (ST_INFO_BIND(data, i) == STB_WEAK)
    return (ST_SHNDX(data, i) == SHN_UNDEF ? 'w' : 'W');
  else if (ST_INFO_BIND(data, i) == STB_WEAK
      && ST_INFO_TYPE(data, i) == STT_OBJECT)
    return (ST_SHNDX(data, i) == SHN_UNDEF ? 'v' : 'V');
  else if (ST_SHNDX(data, i) == SHN_UNDEF)
    return ('U');
  else if (ST_SHNDX(data, i) == SHN_ABS)
    return ('A');
  else if (ST_SHNDX(data, i) == SHN_COMMON)
    return ('C');
  else
    return (sub_get_symbol_char(data, i));
}

void		print_symbol(Elf_data* data)
{
  int		i;
  char	*str;

  i = 0;
  while (i < (int)(SH_SIZE(data, data->symtab_offset) / (IS_32(data) ?
          sizeof(Elf32_Sym) : sizeof(Elf64_Sym))))
  {
    if (SH_OFFSET(data, data->strtab_offset) + ST_NAME(data, i) >= data->fsize)
    {
      printf("Corrupted file\n");
      exit(1);
    }
    str =  (char*)(data->data + SH_OFFSET(data, data->strtab_offset)
        + ST_NAME(data, i));
    if (!(!str || strcmp("", str) == 0))
    {
      if (ST_VALUE(data, i) == 0)
        printf("                 ");
      else
        printf("%016x ", (unsigned int)ST_VALUE(data, i));

      printf("%c %s\n", get_symbol_char(data, i), str);
    }
    ++i;
  }
}

int		nm_obj(const char* filename)
{
  Elf_data	*data;

  if ((data = create_elf_data(filename)) == 0)
  {
    printf("Error: %s\n", strerror(errno));
    return (-1);
  }
  print_symbol(data);
  clean_elf_data(data);
  return (0);
}

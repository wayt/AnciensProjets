/*
** elf_header.h for nm-objdump in /Storage/Epitech/nm-objdump
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Mar 11 13:54:21 2013 maxime ginters
** Last update Sun Mar 17 17:21:47 2013 maxime ginters
*/

#ifndef ELF_HEADER_H_
# define ELF_HEADER_H_

#include <elf.h>

#define IS_32(a) (a->plateform == PLATEFORM_32)
#define IS_64(a) (a->plateform == PLATEFORM_64)

#define STRNDX_32(a) (a->elf32->e_shstrndx)
#define STRNDX_64(a) (a->elf64->e_shstrndx)
#define SHNUM_32(a) (a->elf32->e_shnum)
#define SHNUM_64(a) (a->elf64->e_shnum)
#define SHOFF_32(a) (a->elf32->e_shoff)
#define SHOFF_64(a) (a->elf64->e_shoff)
#define EHSIZE_32(a) (a->elf32->e_ehsize)
#define EHSIZE_64(a) (a->elf64->e_ehsize)
#define PHENTSIZE_32(a) (a->elf32->e_phentsize)
#define PHENTSIZE_64(a) (a->elf64->e_phentsize)
#define PHNUM_32(a) (a->elf32->e_phnum)
#define PHNUM_64(a) (a->elf64->e_phnum)
#define SHENTSIZE_32(a) (a->elf32->e_shentsize)
#define SHENTSIZE_64(a) (a->elf64->e_shentsize)
#define VERSION_32(a) (a->elf32->e_version)
#define VERSION_64(a) (a->elf64->e_version)
#define MACHINE_32(a) (a->elf32->e_machine)
#define MACHINE_64(a) (a->elf64->e_machine)
#define FLAGS_32(a) (a->elf32->e_flags)
#define FLAGS_64(a) (a->elf64->e_flags)
#define ENTRY_32(a) (a->elf32->e_entry)
#define ENTRY_64(a) (a->elf64->e_entry)

#define E_SHSTRNDX(a) (IS_32(a) ? STRNDX_32(a) : STRNDX_64(a))
#define E_SHNUM(a) (IS_32(a) ? SHNUM_32(a) : SHNUM_64(a))
#define E_SHOFF(a) (IS_32(a) ? SHOFF_32(a) : SHOFF_64(a))
#define E_VERSION(a) (IS_32(a) ? VERSION_32(a) : VERSION_64(a))
#define E_MACHINE(a) (IS_32(a) ? MACHINE_32(a) : MACHINE_64(a))
#define E_FLAGS(a) (IS_32(a) ? FLAGS_32(a) : FLAGS_64(a))
#define E_ENTRY(a) (IS_32(a) ? ENTRY_32(a) : ENTRY_64(a))
#define SHHDR(a) (a->data + E_SHOFF(a))
#define STRTAB(a) (a->data + SH_OFFSET(a, E_SHSTRNDX(a)))

#define SH_NAME_32(a, i) (a->shdr32[i].sh_name)
#define SH_NAME_64(a, i) (a->shdr64[i].sh_name)
#define SH_OFFSET_32(a, i) (a->shdr32[i].sh_offset)
#define SH_OFFSET_64(a, i) (a->shdr64[i].sh_offset)
#define SH_SIZE_32(a, i) (a->shdr32[i].sh_size)
#define SH_SIZE_64(a, i) (a->shdr64[i].sh_size)
#define SH_ADDR_32(a, i) (a->shdr32[i].sh_addr)
#define SH_ADDR_64(a, i) (a->shdr64[i].sh_addr)
#define SH_TYPE_32(a, i) (a->shdr32[i].sh_type)
#define SH_TYPE_64(a, i) (a->shdr64[i].sh_type)
#define SH_FLAGS_32(a, i) (a->shdr32[i].sh_flags)
#define SH_FLAGS_64(a, i) (a->shdr64[i].sh_flags)

#define SH_NAME(a, i) (IS_32(a) ? SH_NAME_32(a, i) : SH_NAME_64(a, i))
#define SH_OFFSET(a, i) (IS_32(a) ? SH_OFFSET_32(a, i) : SH_OFFSET_64(a, i))
#define SH_SIZE(a, i) (IS_32(a) ? SH_SIZE_32(a, i) : SH_SIZE_64(a, i))
#define SH_ADDR(a, i) (IS_32(a) ? SH_ADDR_32(a, i) : SH_ADDR_64(a, i))
#define SH_TYPE(a, i) (IS_32(a) ? SH_TYPE_32(a, i) : SH_TYPE_64(a, i))
#define SH_FLAGS(a, i) (IS_32(a) ? SH_FLAGS_32(a, i) : SH_FLAGS_64(a, i))

#define ST_NAME_32(a, i) (a->symtab32[i].st_name)
#define ST_NAME_64(a, i) (a->symtab64[i].st_name)
#define ST_VALUE_32(a, i) (a->symtab32[i].st_value)
#define ST_VALUE_64(a, i) (a->symtab64[i].st_value)
#define ST_INFO_32(a, i) (a->symtab32[i].st_value)
#define ST_INFO_64(a, i) (a->symtab64[i].st_info)
#define ST_SHNDX_32(a, i) (a->symtab32[i].st_shndx)
#define ST_SHNDX_64(a, i) (a->symtab64[i].st_shndx)

#define ST_NAME(a, i) (IS_32(a) ? ST_NAME_32(a, i) : ST_NAME_64(a, i))
#define ST_VALUE(a, i) (IS_32(a) ? ST_VALUE_32(a, i) : ST_VALUE_64(a, i))
#define ST_INFO(a, i) (IS_32(a) ? ST_INFO_32(a, i) : ST_INFO_64(a, i))
#define ST_INFO_BIND(a, i) (IS_32(a) ? ELF32_ST_BIND(ST_INFO_32(a, i)) : ELF64_ST_BIND(ST_INFO_64(a, i)))
#define ST_INFO_TYPE(a, i) (IS_32(a) ? ELF32_ST_TYPE(ST_INFO_32(a, i)) : ELF64_ST_TYPE(ST_INFO_64(a, i)))
#define ST_SHNDX(a, i) (IS_32(a) ? ST_SHNDX_32(a, i) : ST_SHNDX_64(a, i))

typedef enum
{
  PLATEFORM_32	= 0,
  PLATEFORM_64	= 1
} ePlateforms;

typedef struct
{
  const char*	filename;
  ePlateforms	plateform;
  unsigned int	fsize;
  void		*data;
  Elf32_Ehdr	*elf32;
  Elf64_Ehdr	*elf64;
  Elf32_Shdr	*shdr32;
  Elf64_Shdr	*shdr64;
  Elf32_Sym	*symtab32;
  Elf64_Sym	*symtab64;
  int		symtab_offset;
  int		strtab_offset;
  char		*strtab;
} Elf_data;

#endif /* !ELF_HEADER_H_ */

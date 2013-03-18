/*
** nm.h for nm in /Storage/Epitech/nm-objdump/nm
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Mar 13 17:40:28 2013 maxime ginters
** Last update Fri Mar 15 15:51:37 2013 maxime ginters
*/

#ifndef NM_H_
# define NM_H_

#include "elf_header.h"
#include "utils.h"

typedef struct
{
  unsigned int	key;
  char		symbol;
}		t_st_type;
/*
** nm.c
*/
int	nm_obj(const char* filename);

#endif /* !NM_H_ */

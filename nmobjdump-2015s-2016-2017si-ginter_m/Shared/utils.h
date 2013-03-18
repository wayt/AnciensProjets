/*
** utils.h for Shared in /Storage/Epitech/nm-objdump/Shared
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Mar 12 14:34:22 2013 maxime ginters
** Last update Sun Mar 17 17:08:58 2013 maxime ginters
*/

#ifndef UTILS_H_
# define UTILS_H_

#include "elf_header.h"

/*
** utils.c
*/
Elf_data*	create_elf_data(const char *filename);
void		clean_elf_data(Elf_data *data);

/*
** utils2.c
*/
int		fsize(int fd);
void		check_elf_file(int fd);
void		throw_corrupted_file();
void		check_plateform(void *data);

#endif /* !UTILS_H_ */

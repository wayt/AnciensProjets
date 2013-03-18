/*
** err.c for asm in /home/leroy_v/Epitech/corewar/asm
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Tue Dec 04 14:38:09 2012 vincent leroy
** Last update Tue Dec 04 15:18:45 2012 vincent leroy
*/

#include "asm.h"

void	error(char *msg, int quit)
{
  my_printf("%s", msg);
  if (quit != 0)
    exit(1);
}

void	line_error(char *msg, int line, int quit)
{
  my_printf(msg, line);
  if (quit != 0)
    exit(1);
}

void	string_error(char *msg, char *str, int quit)
{
  my_printf(msg, str);
  if (quit != 0)
    exit(1);
}

void	string_line_error(char *msg, char *str, int line, int quit)
{
  my_printf(msg, str, line);
  if (quit != 0)
    exit(1);
}

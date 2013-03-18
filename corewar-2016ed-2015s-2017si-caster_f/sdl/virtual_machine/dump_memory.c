/*
** dump_memory.c for virtual_machine in /home/leroy_v/github/CoreWar/core/virtual_machine
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sun Dec 16 15:15:34 2012 vincent leroy
** Last update Sun Dec 16 15:37:16 2012 vincent leroy
*/

#include "virtual_machine.h"
#include "my.h"
#include "op.h"
#include "corewar.h"

void	print_octet(unsigned char octet)
{
  char	c;

  c = octet / 16;
  if (c > 9)
    c = c - 10 + 'A';
  else
    c = c + '0';
  write(1, &c, 1);
  c = octet % 16;
  if (c > 9)
    c = c - 10 + 'A';
  else
    c = c + '0';
  write(1, &c, 1);
}

void	dump_memory(unsigned char *mem)
{
  unsigned int	i;

  i = 0;
  while (i < MEM_SIZE)
  {
    if (i % 32 == 0)
      my_printf("\n");
    print_octet((unsigned char)mem[i]);
    ++i;
  }
}

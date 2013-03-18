/*
** commands.c for commands in /home/fest/Epitech/CoreWar/core/commands
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Dec 10 15:24:39 2012 maxime ginters
** Last update dim. déc. 16 18:09:09 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "commands.h"
#include "virtual_machine.h"
#include "op.h"

t_cw_cmd	corewar_commands[] = {
  {0x01, 10, handle_live, "live"},
  {0x02, 5, handle_ld, "ld"},
  {0x03, 5, handle_st, "st"},
  {0x04, 10, handle_add, "add"},
  {0x05, 10, handle_sub, "sub"},
  {0x06, 6, handle_and, "and"},
  {0x07, 6, handle_or, "or"},
  {0x08, 6, handle_xor, "xor"},
  {0x09, 20, handle_zjmp, "zjmp"},
  {0x0a, 25, handle_ldi, "ldi"},
  {0x0b, 25, handle_sti, "sti"},
  {0x0c, 800, handle_fork, "fork"},
  {0x0d, 10, handle_lld, "ldd"},
  {0x0e, 50, handle_lldi, "lldi"},
  {0x0f, 1000, handle_lfork, "lfork"},
  {0x10, 2, handle_aff, "aff"},
  {0x11, 10, handle_mul, "mul"},
  {0x12, 10, handle_div, "div"},
  {0x13, 10, handle_mod, "mod"},
  {0x00, 0, NULL, "NULL"},
};

char	get_param_type(unsigned char oct, char index)
{
   char	val;

  index *= 2;
  val = 0;
  val = (oct & (0x03 << index)) >> index;
  if (val == 0x01)
    return (PARAM_REG);
  else if (val == 0x02)
    return (PARAM_DIR);
  else if (val == 0x03)
    return (PARAM_IND);
  return (0);
}

int	get_size_to_read(unsigned char oct, char index)
{
  char	type;

  type = get_param_type(oct, index);
  if (type == PARAM_REG)
    return (1);
  else if (type == PARAM_DIR)
    return (DIR_SIZE);
  else if (type == PARAM_IND)
    return (IND_SIZE);
  return (0);
}

int	avance_mem(int pc, int count)
{
  pc += count;
  while (pc >= MEM_SIZE)
    pc -= MEM_SIZE;
  return (pc);
}

unsigned char	*mem_safecpy(unsigned char *dest, unsigned char *mem,
    int from, int size)
{
  int	i;
  int	src_i;

  src_i = 0;
  i = 0;
  while (i < size)
  {
    if (from + i >= MEM_SIZE)
    {
      from = 0;
      size -= i;
      i = 0;
    }
    dest[src_i] = mem[from + i];
    ++src_i;
    ++i;
  }
  return (dest);
}

int	getnbr_wsize(unsigned char *mem, int pc, int size)
{
  unsigned char	*buff;
  int	val;
  int	i;

  if ((buff = malloc((size + 1)* sizeof(char))) == 0)
    return (0);
  my_memset(buff, 0, size + 1);
  mem_safecpy(buff, mem, pc, size);
  i = 0;
  val = 0;
  while (i < size)
  {
    val = (val << 8) + buff[i];
    ++i;
  }
  free(buff);
  return (val);
}

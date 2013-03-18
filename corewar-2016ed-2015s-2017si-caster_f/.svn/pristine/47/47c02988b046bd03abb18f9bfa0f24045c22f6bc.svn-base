/*
** list_to_hexa.c for asm in /home/leroy_v/github/CoreWar/asm
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Dec 08 14:55:42 2012 vincent leroy
** Last update Fri Dec 14 13:33:11 2012 vincent leroy
*/

#include "asm.h"

int	inverse_int(int nb)
{
  int ret;

  ret = 0;
  if (!is_bigendian())
  {
    char* src = (char*) &nb;
    char* dst = (char*) &ret;
    int i;
    for (i = 0; i < 4; ++i)
      dst[i] = src[4 - i - 1];
  return (ret);
  }
  return (nb);
}

int		count_total_byte(t_list *prog)
{
  int		result;
  int		i;
  t_cmd		*cmd;

  result = 0;
  i = 0;
  while (i < prog->nb_elm)
  {
    cmd = get_data(prog, i);
    result += cmd->byte;
    i++;
  }
  return (result);
}

void		list_to_hexa(t_list *prog, int fd)
{
  header_t	*head;
  int		i;
  t_cmd		*cmd;

  head = prog->data;
  head->magic = inverse_int(COREWAR_EXEC_MAGIC);
  head->prog_size = inverse_int(count_total_byte(prog));
  write(fd, head, sizeof(header_t));
  i = 0;
  while (i < prog->nb_elm)
  {
    cmd = get_data(prog, i);
    write(fd, cmd->cmd_hex, cmd->byte);
    i++;
  }
  my_printf("\t%s\n\t%s\n", head->prog_name, head->comment);
}

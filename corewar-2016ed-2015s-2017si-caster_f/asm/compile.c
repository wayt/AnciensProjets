/*
** compile.c for asm in /home/leroy_v/Epitech/corewar/asm
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Mon Dec 03 16:48:54 2012 vincent leroy
** Last update Sun Dec 16 18:01:47 2012 vincent leroy
*/

#include <stdio.h>
#include "asm.h"

int	count_space(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  return (i);
}

void	free_cmd(t_cmd *cmd)
{
  free(cmd->str);
  free(cmd->cmd);
  free(cmd->mne);
  free_tab(cmd->arg);
  if (cmd->label != NULL)
    free(cmd->label);
  free(cmd);
}

void		compile(int fd, char *name)
{
  char		*s;
  int		line;
  int		fdOut;
  header_t	head;
  t_list	*prog;

  my_memset(&head, 0, sizeof(header_t));
  if ((prog = create_list(&head)) == NULL)
    error(MALLOC_ERROR, 1);
  line = 1;
  while ((s = get_next_line(fd)) != NULL)
  {
    add_cmd(s, line, &head, prog);
    free(s);
    line++;
  }
  create_cmd_hex(prog);
  create_label_hex(prog);
  if ((fdOut = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    string_error(FILE_ERROR, name, 1);
  list_to_hexa(prog, fdOut);
  close(fdOut);
  del_all_list(&prog, &free_cmd, NULL);
}

/*
** process_cmd.c for asm in /home/caster_f/projects/corewar/src/asm
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Dec 07 16:31:20 2012 fabien casters
** Last update Sat Dec 15 17:17:30 2012 fabien casters
*/

#include <stdio.h>
#include "asm.h"

op_t		*get_op(char *mne)
{
  int		i;

  i = 0;
  while (op_tab[i].mnemonique != NULL)
  {
    if (my_strcmp(mne, op_tab[i].mnemonique) == 0)
      return (&op_tab[i]);
    i++;
  }
  return (NULL);
}

void	check_cmd_hex(t_cmd *cmd, op_t *op)
{
  int	i;

  cmd->byte = 1;
  cmd->cmd_hex[0] = op->code;
  if (op->cbyte == 1)
  {
    cmd->cmd_hex[cmd->byte] = get_cbyte(cmd->arg, cmd->line);
    cmd->byte++;
  }
  i = 0;
  while (cmd->arg[i] != NULL)
    i++;
  if (i < op->nbr_args)
    line_error(ARG_INF_ERROR, cmd->line, 1);
  else if (i > op->nbr_args)
    line_error(ARG_SUP_ERROR, cmd->line, 1);
  i = 0;
  while (cmd->arg[i] != NULL)
  {
    if (!(get_type(cmd->arg[i]) & op->type_i[i]))
      line_error(ARG_ERROR, cmd->line, 1);
    i++;
  }
}

void		add_cmd_hex(t_cmd *cmd, unsigned int value, int size, int index)
{
  char		tab[4];
  int		i;

  tab[0] = (value / (256 * 256 * 256)) % 256;
  tab[1] = (value / (256 * 256)) % 256;
  tab[2] = (value / 256) % 256;
  tab[3] = value % 256;
  i = 4 - size;
  while (i < 4)
  {
    cmd->cmd_hex[(index != -1) ? index : cmd->byte] = tab[i];
    if (index != -1)
      index++;
    else
      cmd->byte++;
    i++;
  }
}

void		fill_cmd_hex(t_cmd *cmd, op_t *op)
{
  int	  i;

  i = 0;
  while (cmd->arg[i] != NULL)
  {
    add_cmd_hex(cmd, get_type_value(cmd->arg[i]),
                (get_type(cmd->arg[i]) == T_REG) ? 1 : op->type_o[i], -1);
    i++;
  }
}

void		create_cmd_hex(t_list *list)
{
  int		i;
  t_cmd		*cmd;
  op_t		*op;

  i = 0;
  while (i < list->nb_elm)
  {
    cmd = get_data(list, i);
    if ((op = get_op(cmd->mne)) == NULL)
      line_error(MNE_ERROR, cmd->line, 1);
    cmd->op = op;
    check_cmd_hex(cmd, op);
    fill_cmd_hex(cmd, op);
    i++;
  }
}

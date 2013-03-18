/*
** create_label_cmd2.c for asm in /home/caster_f/projects/corewar/src/asm
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Dec 14 18:00:35 2012 fabien casters
** Last update Sat Dec 15 11:47:48 2012 vincent leroy
*/

#include "asm.h"

int		is_label2(t_list *list, char *label)
{
  t_cmd		*cmd;
  int		i;

  i = 0;
  while (i < list->nb_elm)
  {
    cmd = get_data(list, i);
    if (my_strcmp(cmd->label, label) == 0)
      return (1);
    i++;
  }
  return (0);
}

int		get_sarg(t_cmd *cmd, int i)
{
  if (get_type(cmd->arg[i]) == T_REG)
    return (1);
  return (cmd->op->type_o[i]);
}

unsigned int	fill_label_hex(t_list *list, int i, char *label)
{
  int		k;
  unsigned int	nb;
  t_cmd		*c;

  k = i;
  nb = 0xffffffff;
  while (k >= 0)
  {
    c = get_data(list, k);
    nb -= (k == i) ? 0 : c->byte;
    if (my_strcmp(c->label, label) == 0)
      return (nb + 1);
    k--;
  }
  k = i;
  nb = 0;
  while (k < list->nb_elm)
  {
    c = get_data(list, k);
    if (my_strcmp(c->label, label) == 0)
      return (nb);
    nb += c->byte;
    k++;
  }
  return (-1);
}

char	*get_lname(t_cmd *cmd, int j)
{
  return (&cmd->arg[j][(cmd->arg[j][1] == LABEL_CHAR) + 1]);
}

void		create_label_hex(t_list *list)
{
  t_cmd		*cmd;
  int		i;
  int		j;
  int		pre;

  i = 0;
  while (i < list->nb_elm)
  {
    cmd = get_data(list, i);
    pre = 1 + cmd->op->cbyte;
    j = 0;
    while (cmd->arg[j] != NULL)
    {
      if (cmd->arg[j][0] == LABEL_CHAR || cmd->arg[j][1] == LABEL_CHAR)
      {
        if (!is_label2(list, get_lname(cmd, j)))
          string_line_error(LABEL_ERROR, get_lname(cmd, j), cmd->line, 1);
        add_cmd_hex(cmd, fill_label_hex(list, i, get_lname(cmd, j)),
						get_sarg(cmd, j), pre);
      }
      pre += get_sarg(cmd, j);
      j++;
    }
    i++;
  }
}

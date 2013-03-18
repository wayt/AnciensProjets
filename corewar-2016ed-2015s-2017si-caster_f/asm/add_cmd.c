/*
** add_cmd.c for asm in /home/leroy_v/github/CoreWar/asm
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Fri Dec 07 14:59:34 2012 vincent leroy
** Last update Thu Dec 13 21:08:53 2012 vincent leroy
*/

#include "asm.h"

char	*epur_cmd(char *cmd)
{
  int	i;
  int	j;
  char	*str;

  if ((str = my_malloc(my_strlen(cmd) + 1, MALLOC_ERROR)) == NULL)
    exit(1);
  i = count_space(cmd);
  j = 0;
  while (cmd[i] != '\0' && cmd[i] != ' ' && cmd[i] != '\t')
    str[j++] = cmd[i++];
  if (cmd[i] != '\0')
    str[j++] = ' ';
  while (cmd[i] != '\0')
  {
    if (cmd[i] == COMMENT_CHAR)
      return (str);
    else if (cmd[i] != ' ' && cmd[i] != '\t')
      str[j++] = cmd[i];
    i++;
  }
  return (str);
}

void	traite_line(char *s, t_cmd *cmd, int line, char **label)
{
  char	**tab;
  char	sepa[2];

  sepa[0] = SEPARATOR_CHAR;
  sepa[1] = '\0';
  cmd->cmd = epur_cmd(s);
  tab = my_str_to_wordtab(cmd->cmd, " \t");
  cmd->mne = my_strdup(tab[0]);
  cmd->arg = my_str_to_wordtab(tab[1], sepa);
  cmd->line = line;
  cmd->label = *label;
  *label = NULL;
  free_tab(tab);
}

void	verif_label(char *s, int line)
{
  int	i;
  int	j;
  int	nb;
  char	*label;

  label = LABEL_CHARS;
  i = 0;
  nb = 0;
  while (s[i] != '\0' && s[i] != LABEL_CHAR)
  {
    j = 0;
    while (label[j] != '\0')
    {
      if (s[i] == label[j])
	nb++;
      j++;
    }
    i++;
  }
  if (nb < i)
    line_error(SYNTAX_ERROR, line, 1);
}

int	is_label(char *s, char **label, int line)
{
  int	i;
  int	len;

  i = 0;
  while (s[i] != '\0' && s[i] != LABEL_CHAR)
  {
    if (s[i] == ' ' || s[i] == '\t')
      return (-1);
    i++;
  }
  if (s[i] == '\0')
    return (-1);
  verif_label(s, line);
  i += count_space(s + i + 1) + 1;
  if ((*label = my_malloc(i + 1, MALLOC_ERROR)) == NULL)
    exit(1);
  len = (s[i] == '\0' ? 0 : i);
  i = -1;
  while (s[++i] != LABEL_CHAR)
    (*label)[i] = s[i];
  return (len);
}

void		add_cmd(char *s, int line, header_t *head, t_list *prog)
{
  static char	*label = NULL;
  t_cmd		*cmd;
  int		i;
  int		lab;

  i = count_space(s);
  if (s[i] != COMMENT_CHAR && s[i] != '\0')
  {
    if ((lab = is_label(s + i, &label, line)) == 0)
      return ;
    if (recup_name_comm(s + (lab == -1 ? i : lab + i), line, head) == 0)
    {
      if ((cmd = my_malloc(sizeof(t_cmd), MALLOC_ERROR)) == NULL)
	exit(1);
      cmd->str = my_strdup(s);
      traite_line(s + (lab == -1 ? 0 : lab), cmd, line, &label);
      if (add_last_elm(prog, cmd) != 0)
	error(MALLOC_ERROR, 1);
    }
  }
}

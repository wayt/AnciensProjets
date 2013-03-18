/*
** commandes_parser.c for Minishell2 in /home/fest/Epitech/Minishell2
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Nov 27 17:52:06 2012 maxime ginters
** Last update Fri Nov 30 19:22:40 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "env_functions.h"
#include "chaine.h"
#include "commandes_parser.h"

char	*parse_output(char *str, t_command *cmd)
{
  int	i;
  char	open;
  char *ret;

  i = 0;
  open = 0;
  cmd->output_file = NULL;
  cmd->output_type = OUTPUT_NONE;
  while (str[i] != '\0')
  {
    open = (str[i] == '"' ? !open : open);
    if (str[i] == '>' && open == 0)
    {
      cmd->output_type = (str[i + 1] == '>' ? OUTPUT_APPEND : OUTPUT_NEW);
      ret = my_substr(str, 0, i - 1);
      cmd->output_file = my_trim(my_substr(str,
            i + (str[i + 1] == '>' ? 2 : 1), my_strlen(str) - 1));
      free(str);
      return (ret);
    }
    ++i;
  }
  return (str);
}

char	*parse_intput(char *str, t_command *cmd)
{
  int	i;
  char	open;
  char	*ret;

  i = 0;
  open = 0;
  cmd->input_file = NULL;
  while (str[i] != '\0')
  {
    open = (str[i] == '"' ? !open : open);
    if (str[i] == '<' && open == 0)
    {
      ret = my_substr(str, 0, i - 1);
      cmd->input_file = my_trim(my_substr(str, i + 1, my_strlen(str) - 1));
      free(str);
      return (ret);
    }
    ++i;
  }
  return (str);
}

t_command	*create_sub_command(char *str)
{
  t_command	*new;
  char	**t;
  int	tab_size;
  int	i;

  new = xmalloc(sizeof(t_command));
  str = my_trim(parse_output(str, new));
  str = my_trim(parse_intput(str, new));
  t = my_str_to_wordtab_sep(str, '|');
  tab_size = my_get_tabsize((void**)t);
  new->commands = xmalloc(sizeof(char**) * (tab_size + 1));
  new->commands[tab_size] = NULL;
  new->command_count = tab_size;
  i = -1;
  while (++i < tab_size)
    new->commands[i] = my_str_to_wordtab_sep(my_trim(t[i]), ' ');
  return (new);
}

t_command_node	*create_commands(char *str)
{
  char	**t;
  t_command_node	*prev;
  t_command_node	*node;
  t_command_node	*first;
  int	i;

  first = NULL;
  t = my_str_to_wordtab_sep(my_trim(str), ';');
  i = 0;
  while (t[i])
  {
    node = xmalloc(sizeof(t_command_node));
    node->next = NULL;
    node->cmd = create_sub_command(t[i++]);
    if (!first)
      first = node;
    else if (prev)
      prev->next = node;
    prev = node;
  }
  return (first);
}

void	free_commands(t_command_node *node)
{
  t_command_node	*tmp;
  int	i;

  while (node)
  {
    tmp = node->next;
    safe_free(node->cmd->output_file);
    safe_free(node->cmd->input_file);
    i = -1;
    while (++i < node->cmd->command_count)
      clean_wordtab(node->cmd->commands[i]);
    free(node->cmd->commands);
    free(node->cmd);
    free(node);
    node = tmp;
  }
}

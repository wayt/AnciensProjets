/*
** commandes_parser.h for Minishell2 in /home/fest/Epitech/Minishell2
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Nov 27 17:52:20 2012 maxime ginters
** Last update Fri Nov 30 19:22:29 2012 maxime ginters
*/

#ifndef COMMANDES_PARSER_H_
# define COMMANDES_PARSER_H_

#define OUTPUT_NONE	0
#define OUTPUT_NEW	1
#define OUTPUT_APPEND	2

struct s_command
{
  char	***commands;
  int	command_count;
  char	output_type;
  char	*output_file;
  char	*input_file;
};

typedef struct s_command t_command;

struct s_command_node
{
  struct s_command	*cmd;
  struct s_command_node	*next;
};

typedef struct s_command_node t_command_node;

/*
** commandes_parser.c
*/
t_command	*create_sub_command(char *str);
t_command_node	*create_commands(char *str);
void	free_commands(t_command_node *node);

#endif /* !COMMANDES_PARSER_H_ */

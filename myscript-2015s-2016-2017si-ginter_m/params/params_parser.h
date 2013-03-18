/*
** param_parser.h for my_script in /Storage/Epitech/my_script
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Feb 11 16:41:39 2013 maxime ginters
** Last update Mon Feb 11 17:25:40 2013 maxime ginters
*/

#ifndef PARAM_PARSER_H_
# define PARAM_PARSER_H_

struct s_params
{
  char	append;
  char*	file;
  char*	shell;
};

struct s_params_entry
{
  char	key;
  void	(*fct)(struct s_params*, char**, int);
  const char*	help;
};

typedef struct s_params	t_params;
typedef struct s_params_entry	t_params_entry;

t_params*	create_params(char**, int);
void	clear_params(t_params* params);

extern t_params_entry	params_tab[];



#endif /* !PARAM_PARSER_H_ */

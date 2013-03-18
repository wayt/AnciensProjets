/*
** chaine.h for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 15:19:37 2012 maxime ginters
** Last update Sat Nov 10 16:45:03 2012 maxime ginters
*/

#ifndef CHAINE_H_
# define CHAINE_H_

struct s_env_node
{
  char	*name;
  char	*value;
  struct s_env_node	*next;
};

struct s_env
{
  struct s_env_node	*list;
  char	**environ;
  char	*username;
};

typedef struct s_env_node t_env_node;
typedef struct s_env t_env;
/*
** create_functions.c
*/
t_env	*create_environ(char **env);
t_env_node	*create_from_tab(char **env);
t_env_node	*append_new(t_env_node *list, char *name, char *value);
char	**convert_to_tab(t_env_node *list);

/*
** find_functions.c
*/
t_env_node	*find_node(t_env_node *list, char *name);
char	*find_value(t_env_node *list, char *name);

/*
** mod_functions.c
*/
void	update_value(t_env_node *list, char *name, char *newvalue);
void	delete_entry(t_env_node **list, char *name);
void	clean_list(t_env_node **list);
void	free_full_env(t_env *env);

#endif /* !CHAINE_H_ */

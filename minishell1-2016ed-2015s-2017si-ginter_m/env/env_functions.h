/*
** env_functions.h for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 03 16:40:17 2012 maxime ginters
** Last update Sat Nov 10 16:45:08 2012 maxime ginters
*/

#ifndef ENV_FUNCTIONS_H_
# define ENV_FUNCTIONS_H_

#include <unistd.h>
#include "chaine.h"

char	*get_field_name(char *str);
char	*get_field_value(char *str);
char	*comput_path(t_env_node *list, char *name);
char	*search_default_path(char *name);

#endif /* !ENV_FUNCTIONS_H_ */

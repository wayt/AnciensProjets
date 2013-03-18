/*
** env_functions.c for MiniShell1 in /home/fest/Epitech/MiniShell1
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 03 16:40:09 2012 maxime ginters
** Last update Sat Nov 10 16:01:59 2012 maxime ginters
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"
#include "env_functions.h"

char	*get_field_name(char *str)
{
  int	i;
  int	pos;
  char	*name;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '=')
    {
      name = malloc((i + 2) * sizeof(char));
      if (name == NULL)
        return (NULL);
      my_memset(name, 0x0, i + 2);
      pos = 0;
      while (pos < i)
      {
        name[pos] = str[pos];
        ++pos;
      }
      name[pos] = '\0';
      return (name);
    }
    ++i;
  }
  return (NULL);
}

char	*get_field_value(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '=' && str[i + 1] != '\0')
      return (my_strdup(&str[i + 1]));
    ++i;
  }
  return (NULL);
}

char	*test_path(char *str, char *name)
{
  char	*path;

  path = my_strdup(str);
  path = my_strcat(path, "/");
  path = my_strcat(path, name);
  if (access(path, X_OK) == 0)
    return (path);
  free(path);
  return (NULL);
}

char	*comput_path(t_env_node *list, char *name)
{
  char	*path;
  char	**t;
  int	i;

  if ((path = find_value(list, "PATH")) == NULL)
  {
    path = search_default_path(name);
    if (path != NULL)
      return (path);
    return (my_strdup(name));
  }
  t = my_str_to_wordtab_sep(path, ':');
  free(path);
  i = 0;
  while (t[i] != NULL)
  {
    path = test_path(t[i], name);
    if (path != NULL)
      return (path);
    ++i;
  }
  clean_wordtab(t);
  if ((name[0] == '.' && name[1] == '/') || name[0] == '/')
    return (my_strdup(name));
  return (NULL);
}

char	*search_default_path(char *name)
{
  char	*path;
  int	size;

  size = 4 + my_strlen(name) + 1;
  path = xmalloc(size * sizeof(char));
  my_memset(path, 0x0, size);
  my_strcpy(path, "/bin/");
  path = my_strcat(path, name);
  if (access(path, X_OK) == 0)
    return (path);
  free(path);
  return (NULL);
}

/*
** header.c for asm in /home/leroy_v/github/CoreWar/asm
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Wed Dec 05 14:14:14 2012 vincent leroy
** Last update Wed Dec 12 13:58:25 2012 vincent leroy
*/

#include "asm.h"

int	is_name_comment(char *line)
{
  if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
    return (1);
  if (my_strncmp(line, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) == 0)
    return (2);
  return (0);
}

void	name_is_valid(char *line, int l, int name)
{
  int	i;

  i = (name == 1 ? my_strlen(NAME_CMD_STRING) : my_strlen(COMMENT_CMD_STRING));
  while (line[i] != '"' && line[i] != '\0')
  {
    if (line[i] != ' ' && line[i] != '\t')
      line_error(SYNTAX_ERROR, l, 1);
    i++;
  }
  i++;
  while (line[i] != '"' && line[i] != '\0')
    i++;
  if (line[i] == '\0')
    line_error(STRING_ERROR, l, 1);
}

char	*copy_string(char *line)
{
  int	i;
  int	j;
  char	*s;

  i = 0;
  while (line[i] != '\0' && line[i] != '"')
    i++;
  if ((s = my_malloc(my_strlen(line) - i, MALLOC_ERROR)) == NULL)
    exit(1);
  j = i + 1;
  while (line[j] != '\0' && line[j] != '"')
  {
    s[j - (i + 1)] = line[j];
    j++;
  }
  return (s);
}

int	recup_name_comm(char *line, int l, header_t *head)
{
  int	name;
  char	*s;

  if ((name = is_name_comment(line)) == 0)
    return (0);
  name_is_valid(line, l, name);
  s = copy_string(line);
  if (name == 1)
    my_strncpy(head->prog_name, s, PROG_NAME_LENGTH);
  else
    my_strncpy(head->comment, s, COMMENT_LENGTH);
  free(s);
  return (1);
}

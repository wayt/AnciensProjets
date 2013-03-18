/*
** get_type.c for asm in /home/caster_f/projects/corewar/src/asm
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Dec 04 17:15:49 2012 fabien casters
** Last update Sun Dec 16 18:11:25 2012 vincent leroy
*/

#include "op.h"
#include "asm.h"

int	is_num(char *str)
{
  int	i;

  i = (str[0] == '-');
  while (str[i] != '\0')
  {
    if ('0' > str[i] || str[i] > '9')
      return (0);
    i++;
  }
  return (1);
}

int	get_type(char *data)
{
  if (data[0] == DIRECT_CHAR && is_num(&data[1]))
    return (T_DIR);
  else if (data[0] == DIRECT_CHAR && data[1] == LABEL_CHAR)
    return (T_DIR);
  else if (data[0] == 'r' && is_num(&data[1]))
    return (T_REG);
  else if (data[0] == LABEL_CHAR)
    return (T_IND);
  else if (is_num(data))
    return (T_IND);
  return (0);
}

unsigned int	get_type_value(char *data)
{
  if (data[0] == DIRECT_CHAR && is_num(&data[1]))
    return (my_getnbr(&data[1]));
  else if (data[0] == DIRECT_CHAR && data[1] == LABEL_CHAR)
    return (0);
  else if (data[0] == 'r' && is_num(&data[1]))
    return (my_getnbr(&data[1]));
  else if (is_num(data))
    return (my_getnbr(data));
  else if (data[0] == LABEL_CHAR)
    return (0);
  return (0);
}

char	get_cbyte(char **tab, int line)
{
  int	i;
  int	type;
  char	result;

  i = 0;
  result = 0;
  while (tab[i] != NULL)
  {
    type = get_type(tab[i]);
    if (type == 0)
      line_error(TYPE_ERROR, line, 1);
    result = result << 2;
    result += ((type == T_IND) ? 3 : type);
    i++;
  }
  while (i <= 3)
  {
    result = result << 2;
    i++;
  }
  return (result);
}

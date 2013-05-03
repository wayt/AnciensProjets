/*
** panties.c for my_irc in /home/vaga/Projects/tek2/myirc/src_shared
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Thu Apr 25 15:13:19 2013 fabien casters
** Last update Thu Apr 25 15:22:53 2013 fabien casters
*/

#include <string.h>
#include <stdio.h>
#include "panties.h"

char		*ltrim(char *str)
{
  while (isspace(str[0]))
    str++;
  return (str);
}

char		*rtrim(char *str)
{
  int		i;

  i = strlen(str) - 1;
  while (isspace(str[i]))
  {
    str[i] = '\0';
    --i;
  }
  return (str);
}

char		*trim(char *str)
{
  return ltrim(rtrim(str));
}

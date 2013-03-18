/*
** my_str_to_wordtab.c for ex_04 in /home/ginter_m/Jour_08/ex_04
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Oct 10 12:07:18 2012 maxime ginters
** Last update Thu Oct 11 14:11:24 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

void	mod_size(int *size, int *i)
{
  ++*size;
  ++*i;
}

void	update_no_printable(char *str, int *i)
{
  while (my_isalpha(str[*i]) == 0 && my_isnum(str[*i]) == 0 && str[*i] != '\0')
    ++*i;
}

int	get_row_count_for_the_fucking_malloc(char *str)
{
  int	i;
  int	size;

  size = 1;
  i = 0;
  update_no_printable(str, &i);
  while (str[i] != '\0')
  {
    if (my_isalpha(str[i]) == 0 && my_isnum(str[i]) == 0)
    {
      ++size;
      update_no_printable(str, &i);
    }
    else
      ++i;
  }
  return (size);
}

char	**do_malloc_the_fucking_tab(char **t, char *str)
{
  int	i;
  int	size;
  int	row;

  t = malloc((get_row_count_for_the_fucking_malloc(str) + 1) * sizeof(char*));
  i = 0;
  size = 0;
  row = 0;
  update_no_printable(str, &i);
  while (1 == 1)
    if (my_isalpha(str[i]) == 1 ||  my_isnum(str[i]) == 1)
      mod_size(&size, &i);
    else
    {
      t[row++] = malloc((size + 1) * sizeof(char));
      size = 0;
      update_no_printable(str, &i);
      if (str[i] == '\0')
      {
        t[row] = malloc(1 * sizeof(char));
        return (t);
      }
    }
  return (MY_NULL);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  char	**result;
  int	row;
  int	col;

  result = do_malloc_the_fucking_tab(result, str);
  i = 0;
  row = 0;
  col = 0;
  update_no_printable(str, &i);
  while (1 == 1 && result != MY_NULL)
    if (my_isalpha(str[i]) == 1 || my_isnum(str[i]) == 1)
      result[row][col++] = str[i++];
    else
    {
      result[row++][col] = '\0';
      col = 0;
      update_no_printable(str, &i);
      if (str[i] == '\0')
      {
        result[row][col] = 0;
        return (result);
      }
    }
  return (MY_NULL);
}

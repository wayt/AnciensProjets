/*
** get_next_line.c for GetNextLine in /home/fest/Epitech/GetNextLine
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Nov 24 16:43:43 2012 maxime ginters
** Last update Sun Dec 02 22:36:26 2012 maxime ginters
*/

#include <stdlib.h>
#include "get_next_line.h"

void	buff_set(char	*buff, char value, int size)
{
  int	i;

  i = 0;
  while (i < size)
  {
    buff[i] = value;
    ++i;
  }
}

char	*cut_at_index(char buff[READ_SIZE + 1], int from, int to)
{
  char	*str;
  int	j;

  str = malloc(((to - from + 1) + 1) * sizeof(char));
  if (!str)
    return (NULL);
  buff_set(str, '\0', (to - from + 1) + 1);
  j = 0;
  while (from < to)
    str[j++] = buff[from++];
  return (str);
}

int	my_strlen(char *str)
{
  return (1 + (!str ? -1 : (*str == '\0' ? 0 : my_strlen(++str))));
}

char	*cat_clean(char *pbuff, char *nbuff)
{
  char	*str;
  int	i[2];

  str = malloc((my_strlen(pbuff) + my_strlen(nbuff) + 1) * sizeof(char));
  if (!str)
    return (NULL);
  i[0] = 0;
  i[1] = 0;
  while (pbuff && pbuff[i[0]] != '\0')
    str[i[0]] = pbuff[i[0]++];
  if (pbuff)
  {
    free(pbuff);
  }
  while (nbuff[i[1]] != '\0')
    str[i[0]++] = nbuff[i[1]++];
  str[i[0]] = '\0';
  return (str);

}

char	*get_next_line(const int fd)
{
  char	buff[READ_SIZE + 1];
  int	size;
  int	i;
  static char	*s_buff = NULL;
  char	*ret;

  buff_set(buff, '\0', READ_SIZE + 1);
  while (size = read(fd, buff, READ_SIZE))
  {
    i = 0;
    while (i < size)
      if (buff[i++] == '\n')
      {
        ret = cat_clean(s_buff, cut_at_index(buff, 0, i - 1));
        s_buff = cut_at_index(buff, i , my_strlen(buff) - 1);
        return (ret);
      }
    s_buff = cat_clean(s_buff, buff);
    buff_set(buff, '\0', READ_SIZE + 1);
  }
  if ((size = my_strlen(s_buff)) > 0)
  {
    i = 0;
    while (i < size)
      if (s_buff[i++] == '\n')
      {
        ret = cut_at_index(s_buff, 0, i - 1);
        s_buff = cut_at_index(s_buff, i, size - 1);
        return (ret);
      }
  }
  return (NULL);
}

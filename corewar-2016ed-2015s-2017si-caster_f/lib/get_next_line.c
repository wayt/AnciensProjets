/*
** get_next_line.c for get_next_line in /home/leroy_v/Epitech/get_next_line
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Fri Nov 30 14:20:03 2012 vincent leroy
** Last update Fri Nov 30 21:01:23 2012 vincent leroy
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#if (CHAR_READ < 1)
#error Le nombre de caractere a lire doit etre superieur a 0
#endif

char	*my_realloc(char *ptr, int newsize)
{
  char	*p;
  int	i;

  if ((p = malloc(newsize)) == NULL)
    return (NULL);
  i = 0;
  while (i < newsize)
    p[i++] = '\0';
  if (ptr != NULL)
  {
    i = 0;
    while (i < newsize && ptr[i] != '\0')
    {
      p[i] = ptr[i];
      i++;
    }
    free(ptr);
  }
  return (p);
}

char	*my_strncat(char *s1, char *s2, int n, int cpy)
{
  int	i;
  int	len;

  if (s1 == NULL || s2 == NULL)
    return (NULL);
  i = 0;
  len = 0;
  if (cpy == 0)
    while (s1[len] != '\0')
      len++;
  while (s2[i] != '\0' && (i < n || n < 0))
  {
    s1[i + len] = s2[i];
    i++;
  }
  s1[i + len] = '\0';
  return (s1);
}

char	*recup_char(char *p, char **buff, int m)
{
  int	i;
  int	len;
  char	*b;

  if (p[0] == '\0' && (*buff)[0] == '\0')
    return (NULL);
  i = 0;
  while (p[i] != '\0')
    i++;
  len = 0;
  if (m != 0)
  {
    while ((*buff)[len] != '\0')
      len++;
    if ((b = my_realloc(NULL, len + 1)) == NULL)
      return (NULL);
    my_strncat(b, *buff, -1, 1);
  }
  if ((*buff = my_realloc((m == 0 ? NULL : *buff), i + CHAR_READ + 1)) == NULL)
    return (NULL);
  my_strncat(*buff, p, -1, 1);
  my_strncat(*buff, b, (m == 0 ? 0 : -1), 0);
  if (m != 0)
    free(b);
  return (*buff);
}

char	*recu(const int fd, char **buff, int len)
{
  int	i;
  char	*b;

  if ((b = get_next_line(fd)) == NULL)
    return (*buff);
  i = 0;
  while (b[i] != '\0')
    i++;
  if ((*buff = my_realloc(*buff, i + len + 1)) == NULL)
    return (NULL);
  my_strncat(*buff, b, -1, 0);
  free(b);
  return (*buff);
}

char		*get_next_line(const int fd)
{
  static char	p[CHAR_READ + 1] = {'\0'};
  char		*buff;
  int		res;
  int		i;

  if ((buff = my_realloc(NULL, CHAR_READ + 1)) == NULL)
    return (NULL);
  if ((res = read(fd, buff, CHAR_READ)) < 0)
    return (NULL);
  if (recup_char(p, &buff, 1) == NULL)
  {
    free(buff);
    return (NULL);
  }
  p[0] = '\0';
  i = 0;
  while (buff[i] != '\0' && buff[i] != '\n')
    i++;
  if (buff[i] == '\0')
    return (recu(fd, &buff, i));
  buff[i] = '\0';
  my_strncat(p, buff + i + 1, -1, 0);
  return (buff);
}

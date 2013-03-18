/*
** my_create_str.c for src in /home/leroy_v/Epitech/piscine/lib/src
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Thu Nov 15 10:29:39 2012 vincent leroy
** Last update Mon Dec 03 16:16:15 2012 vincent leroy
*/

#include <stdlib.h>
#include "my.h"

void	*my_malloc(int len, char *msg)
{
  void	*buff;

  if ((buff = malloc(len)) == NULL)
  {
    my_printf(msg);
    return (NULL);
  }
  my_memset(buff, 0, len);
  return (buff);
}

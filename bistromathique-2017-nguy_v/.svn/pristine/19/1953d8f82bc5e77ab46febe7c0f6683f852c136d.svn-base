/*
** xmalloc.c for libmy in /home/fest/Epitech/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 15:37:39 2012 maxime ginters
** Last update Thu Nov 08 15:58:18 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"

void	*xmalloc(unsigned int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
  {
    my_putstr("Error : fail malloc\n");
    exit(1);
  }
  return (ptr);
}


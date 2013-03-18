/*
** my_putstr.c for my_putstr in /home/leroy_v//Jour_04/exo02
** 
** Made by vincent leroy
** Login   <leroy_v@epitech.net>
** 
** Started on  Thu Oct  4 09:33:46 2012 vincent leroy
** Last update Fri Nov 16 16:47:14 2012 leroy_v
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  if (str == 0)
    return (my_putstr("(null)"));
  return (write(1, str, my_strlen(str)));
}

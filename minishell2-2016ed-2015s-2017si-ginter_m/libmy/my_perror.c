/*
** my_perror.c for libmy in /home/fest/Epitech/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 10 14:31:20 2012 maxime ginters
** Last update Thu Nov 29 13:40:48 2012 maxime ginters
*/

#include "my.h"

int	my_perror(char *str)
{
  if (!str)
    return;
  return (write(2, str, my_strlen(str)));
}

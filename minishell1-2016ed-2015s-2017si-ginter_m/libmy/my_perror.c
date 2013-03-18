/*
** my_perror.c for libmy in /home/fest/Epitech/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Nov 10 14:31:20 2012 maxime ginters
** Last update Sat Nov 10 14:38:25 2012 maxime ginters
*/

#include "my.h"

void	my_perror(char *str)
{
  if (!str)
    return;
  while (*str != '\0')
    write(2, str++, 1);
}

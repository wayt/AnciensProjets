/*
** my_putstr.c for bcpe042colle3-2017-ginter_m in /home/fest/Epitech/bcpe042colle3-2017-ginter_m
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Oct 27 17:37:03 2012 maxime ginters
** Last update Sat Oct 27 17:51:07 2012 maxime ginters
*/

#include "utils.h"

void	my_putstr(char *str)
{
  int	i;

  if (!str)
    return ;
  i = 0;
  while (str[i] != '\0')
      write(1, &str[i++], 1);
}

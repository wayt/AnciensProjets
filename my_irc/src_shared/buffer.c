/*
** buffer.c for src_shared in /home/fest/Epitech/my_irc/src_shared
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 25 12:27:27 2013 maxime ginters
** Last update Thu Apr 25 14:48:21 2013 maxime ginters
*/

#include <string.h>
#include "buffer.h"

void	init_buffer(t_buffer *buff)
{
    memset(buff->buff, 0, BUFFER_SIZE);
    buff->wr_index = 0;
    buff->rd_index = 0;
    buff->size = 0;
}

int		safe_memcpy(char buffer[], t_buffer *buff, int size)
{
    int	i;
    int	rd;

    if (buff->size < size)
        return (-1);
    i = 0;
    rd = SAFE_RDINDEX(buff);
    while (i < size)
    {
        buffer[i] = buff->buff[(int)(rd % BUFFER_SIZE)];
        ++i;
        ++rd;
    }
    return (0);
}

int	move_rdindex(t_buffer *buff, int size, int ask)
{
    if (buff->size < size + ask)
        return (-1);
    buff->rd_index = (buff->rd_index + size) % BUFFER_SIZE;
    buff->size -= size;
    return (0);
}

void	move_wrindex(t_buffer *buff, int size)
{
  buff->wr_index = (buff->wr_index + size) % BUFFER_SIZE;
  buff->size += size;
}

int	get_wr_size(t_buffer *buff)
{
  if (buff->wr_index < buff->rd_index)
    return (buff->rd_index - buff->wr_index);
  return (BUFFER_SIZE - (SAFE_WRINDEX(buff)));
}

/*
** keys.c for myirc in /home/vaga/Projects/tek2/myirc/src_client/ncurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sun Apr 28 16:10:52 2013 fabien casters
** Last update Sun Apr 28 16:21:22 2013 fabien casters
*/

#include <string.h>
#include "interface.h"
#include "iinput.h"

int		key_delete(char *buf, int *index, t_interface *in)
{
    *index = *index - 1;
    buf[*index] = '\0';
    refresh_input(in, buf);
    return (0);
}

int		key_send(char *buf, char *dst, int *index, t_interface *in)
{
    *index = 0;
    refresh_input(in, "");
    memcpy(dst, buf, strlen(buf) + 1);
    return (1);
}

int		key_insert(char *buf, int key, int *index, t_interface *in)
{
    buf[*index] = (char)key;
    buf[*index + 1] = '\0';
    *index = *index + 1;
    refresh_input(in, buf);
    return (0);
}

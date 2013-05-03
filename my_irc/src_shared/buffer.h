/*
** buffer.h for src_shared in /home/fest/Epitech/my_irc/src_shared
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Apr 25 12:19:10 2013 maxime ginters
** Last update Thu Apr 25 14:43:31 2013 maxime ginters
*/

#ifndef BUFFER_H_
# define BUFFER_H_

#define BUFFER_SIZE 4096
#define SAFE_RDINDEX(a) ((a)->rd_index % BUFFER_SIZE)
#define SAFE_WRINDEX(a) ((a)->wr_index % BUFFER_SIZE)
#define WR_SIZE(a) (BUFFER_SIZE - (SAFE_WRINDEX(a)))
#define BUFF_WR(a) ((a)->buff + SAFE_WRINDEX(a))

typedef struct
{
    char	buff[4096];
    int		wr_index;
    int		rd_index;
    int		size;

}			t_buffer;

void	init_buffer(t_buffer *buff);
int	safe_memcpy(char buffer[], t_buffer *buff, int size);
int	move_rdindex(t_buffer *buff, int size, int ask);
void	move_wrindex(t_buffer *buff, int size);
int	get_wr_size(t_buffer *buff);

#endif /* !BUFFER_H_ */

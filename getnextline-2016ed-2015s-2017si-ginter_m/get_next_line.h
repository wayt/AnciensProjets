/*
** get_next_line.h for GetNextLine in /home/fest/Epitech/GetNextLine
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Nov 24 16:43:48 2012 maxime ginters
** Last update Mon Nov 26 14:41:44 2012 maxime ginters
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

/*#define READ_SIZE	4096*/
#define READ_SIZE	3

#ifndef NULL
  #define NULL 0x0
#endif

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */

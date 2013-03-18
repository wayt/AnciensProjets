/*
** my_select.h for MySelect in /home/fest/Epitech/MySelect
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Nov 19 15:07:47 2012 maxime ginters
** Last update Fri Nov 23 19:24:24 2012 maxime ginters
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

#include <termios.h>
#include "list.h"

/*
** my_select.c
*/
void	print_args();
void	init_term();
void	read_input();


/*
** utils.c
*/
void	get_winsize(int *row, int *col);
void	goto_pos(int row, int col);
void	put_ctrl(char *str);
void	write_tty(char *str);

/*
** window_utils.c
*/
void	print_row(t_list *elem);
int	ask_enlarge_window();
void	set_cursor_pos(int row, int col, int *p_row, int *p_col);

#endif /* !MY_SELECT_H_ */


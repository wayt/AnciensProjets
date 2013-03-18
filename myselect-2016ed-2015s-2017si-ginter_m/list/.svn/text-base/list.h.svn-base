/*
** list.h for list in /home/fest/Epitech/MySelect/list
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Mon Nov 19 11:26:26 2012 maxime ginters
** Last update Thu Nov 22 18:55:11 2012 maxime ginters
*/

#ifndef LIST_H_
# define LIST_H_

#include "my.h"

struct s_list
{
  char		*str;
  unsigned char	selected;
  unsigned char	focus;
  struct s_list	*next;
};
typedef struct s_list t_list;

/*
** create_list.c
*/
t_list	*create_list(int size, char **strs);

/*
** free_list.c
*/
void	free_list(t_list *list);
void	remove_focused_item(t_list **list);

/*
** find_list.c
*/
t_list	*get_elem_at_index(t_list *list, unsigned int index);
t_list	*get_focus_elem(t_list *list);
int	get_max_strlen(t_list *list);

/*
** list_utils.c
*/
int	get_cursor_pos(t_list *list);
int	get_list_size(t_list *list);
void	up_focus(t_list *list);
void	down_focus(t_list *list);

#endif /* !LIST_H_ */

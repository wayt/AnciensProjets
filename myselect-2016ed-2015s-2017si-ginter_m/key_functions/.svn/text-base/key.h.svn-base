/*
** key.h for key_functions in /home/fest/Epitech/MySelect/key_functions
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Nov 21 15:33:26 2012 maxime ginters
** Last update Fri Nov 23 16:09:33 2012 maxime ginters
*/

#ifndef KEY_H_
# define KEY_H_

#include "list.h"

#define TOUCH_UP	0x00415B1B
#define TOUCH_DOWN	0x00425B1B
#define TOUCH_RIGHT	0x00435B1B
#define TOUCH_LEFT	0x00445B1B
#define TOUCH_SPACE	0x00000020
#define TOUCH_ENTER	0x0000000A
#define TOUCH_DEL	2117294875
#define TOUCH_BCKSPACE	127

struct s_key_function
{
  int	key;
  void	(*funct)(t_list **list);
};

typedef struct s_key_function t_key_function;

void	handle_up(t_list **list);
void	handle_down(t_list **list);
void	handle_right(t_list **list);
void	handle_left(t_list **list);
void	handle_space(t_list **list);
void	handle_enter(t_list **list);
void	handle_delete(t_list **list);
void	handle_null(t_list **list);

static t_key_function	key_functions[] = {
  {TOUCH_UP, handle_up},
  {TOUCH_DOWN, handle_down},
  {TOUCH_RIGHT, handle_right},
  {TOUCH_LEFT, handle_left},
  {TOUCH_SPACE, handle_space},
  {TOUCH_ENTER, handle_enter},
  {TOUCH_DEL, handle_delete},
  {TOUCH_BCKSPACE, handle_delete},
  {0, handle_null}
};

#endif /* !KEY_H_ */

/*
** list.h for ex02 in /Storage/Epitech/old/Piscine_tek2/piscine_cpp_d02a-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 22 11:31:59 2013 maxime ginters
** Last update Sun Apr 28 18:51:16 2013 maxime ginters
*/

#ifndef LIST_H_
# define LIST_H_

/*
** Types
*/

typedef enum e_bool
{
    LFALSE,
    LTRUE
}            t_bool;

typedef struct  s_node
{
    void            *value;
    struct s_node   *next;
}               t_node;

typedef t_node   *t_list;

/*
** Functions
*/

/* Informations */

unsigned int    list_get_size(t_list list);
t_bool          list_is_empty(t_list list);

typedef void    (*t_value_displayer)(void *value);

void            list_dump(t_list list, t_value_displayer val_disp);

/* Modification */

#define PUSH_BACK(a, b) list_add_elem_at_back(a, b)
#define PUSH_FRONT(a, b) list_add_elem_at_front(a, b)

t_bool  list_add_elem_at_front(t_list *front_ptr, void *elem);
t_bool  list_add_elem_at_back(t_list *front_ptr, void *elem);
t_bool  list_add_elem_at_position(t_list *front_ptr, void *elem, unsigned int position);

t_bool  list_del_elem_at_front(t_list *front_ptr);
t_bool  list_del_elem_at_back(t_list *front_ptr);
t_bool  list_del_elem_at_position(t_list *front_ptr, unsigned int position);

void    list_clear(t_list *front_ptr);

/* Value Access */

#define GET_AT(a, b) list_get_elem_at_position(a, b)

void    *list_get_elem_at_front(t_list list);
void    *list_get_elem_at_back(t_list list);
void    *list_get_elem_at_position(t_list list, unsigned int position);

/* Node Access */

typedef int (*t_value_comparator)(void *first, void *second);

t_node  *list_get_first_node_with_value(t_list list, void *value, t_value_comparator val_comp);

#endif /* !LIST_H_ */

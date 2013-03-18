/*
** generic_list.c for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02a-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 15:15:06 2013 maxime ginters
** Last update Thu Jan 10 17:37:00 2013 maxime ginters
*/

#include <stdlib.h>
#include "generic_list.h"

unsigned int list_get_size(t_list list)
{
    unsigned int count = 0;
    while (list != NULL)
    {
        ++count;
        list = list->next;
    }
    return count;
}

t_bool list_is_empty(t_list list)
{
    return (list == NULL ? TRUE : FALSE);
}

void list_dump(t_list list, t_value_displayer val_disp)
{
    while (list != NULL)
    {
        (val_disp)(list->value);
        list = list->next;
    }
}

t_bool list_add_elem_at_front(t_list* front_ptr, void* elem)
{
    t_list new_elem;

    if ((new_elem = malloc(sizeof(t_node))) == NULL)
        return FALSE;
    new_elem->next = *front_ptr;
    *front_ptr = new_elem;
    new_elem->value = elem;
    return TRUE;
}

t_bool list_add_elem_at_back(t_list* front_ptr, void* elem)
{
    t_list last_elem;
    t_list new_elem;

    last_elem = *front_ptr;
    if (last_elem != NULL)
        while (last_elem->next != NULL)
            last_elem = last_elem->next;
    if ((new_elem = malloc(sizeof(t_node))) == NULL)
        return FALSE;
    new_elem->value = elem;
    if (last_elem)
        last_elem->next = new_elem;
    else
        *front_ptr = new_elem;
    return TRUE;
}

t_bool list_add_elem_at_position(t_list* front_ptr, void* elem, unsigned int position)
{
    unsigned int i;
    t_list prev_elem;
    t_list new_elem;

    if (position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    if (*front_ptr == NULL)
        return FALSE;

    if ((new_elem = malloc(sizeof(t_node))) == NULL)
        return FALSE;
    new_elem->value = elem;

    prev_elem = *front_ptr;
    i = 1;
    while (prev_elem->next != NULL && i != position)
    {
        ++i;
        prev_elem = prev_elem->next;
    }
    prev_elem->next = new_elem;
    return TRUE;
}

t_bool list_del_elem_at_front(t_list* front_ptr)
{
    if (*front_ptr == NULL)
        return FALSE;
    *front_ptr = (*front_ptr)->next;
    if (*front_ptr == NULL)
        return FALSE;
    return TRUE;
}

t_bool list_del_elem_at_back(t_list* front_ptr)
{
    t_list new_last;

    if (*front_ptr == NULL)
        return FALSE;
    if ((*front_ptr)->next == NULL)
    {
        *front_ptr = NULL;
        return FALSE;
    }
    new_last = *front_ptr;
    while (new_last->next->next)
        new_last = new_last->next;
    new_last->next = NULL;
    return TRUE;
}

t_bool list_del_elem_at_position(t_list* front_ptr, unsigned int position)
{
    unsigned int i;
    t_list elem;

    if (position == 0)
        return list_del_elem_at_front(front_ptr);

    if (*front_ptr == NULL)
        return FALSE;
    elem = *front_ptr;
    i = 1;
    while (i != position && elem->next)
    {
        ++i;
        elem = elem->next;
    }
    if (i != position || elem->next == NULL)
        return FALSE;
    elem->next = elem->next->next;
    return TRUE;
}

void* list_get_elem_at_front(t_list list)
{
    if (list == NULL)
        return NULL;
    return list->value;
}

void* list_get_elem_at_back(t_list list)
{
    if (list == NULL)
        return NULL;
    while (list->next != NULL)
        list = list->next;
    return list->value;
}

void* list_get_elem_at_position(t_list list, unsigned int position)
{
    unsigned int i;

    if (list == NULL)
        return NULL;
    if (position == 0)
        return list_get_elem_at_front(list);
    i = 0;
    while (i != position && list != NULL)
        list = list->next;
    if (i != position || list == NULL)
        return NULL;
    return list->value;
}

t_node* list_get_first_node_with_value(t_list list, void* value, t_value_comparator val_comp)
{
    while (list != NULL)
    {
        if ((val_comp)(list->value, value) == 0)
            return list;
        list = list->next;
    }
    return NULL;
}

void list_clear(t_list* front_ptr)
{
    *front_ptr = NULL;
}

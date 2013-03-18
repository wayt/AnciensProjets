/*
** stack.c for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02a-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 18:03:53 2013 maxime ginters
** Last update Thu Jan 10 18:16:28 2013 maxime ginters
*/

#include <stdlib.h>
#include "stack.h"
#include "generic_list.h"

unsigned int stack_get_size(t_stack stack)
{
    return list_get_size(stack);
}

t_bool stack_is_empty(t_stack stack)
{
    return list_is_empty(stack);
}

t_bool stack_push(t_stack* stack_ptr, void* elem)
{
    return list_add_elem_at_back(stack_ptr, elem);
}

t_bool stack_pop(t_stack* stack_ptr)
{
    return list_del_elem_at_back(stack_ptr);
}

void* stack_top(t_stack stack)
{
    return list_get_elem_at_back(stack);
}

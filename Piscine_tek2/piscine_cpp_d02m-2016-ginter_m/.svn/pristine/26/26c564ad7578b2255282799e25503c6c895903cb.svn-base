/*
** add.c for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02m-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 12:38:03 2013 maxime ginters
** Last update Thu Jan 10 13:11:03 2013 maxime ginters
*/

#include "castmania.h"

#define ABS(a) (((a) < 0) ? -(a) : (a))

int normal_add(int a, int b)
{
    return a + b;
}

int absolute_add(int a, int b)
{
    return ABS(a + b);
}

void exec_add(t_add* operation)
{
    if (operation->add_type == NORMAL)
        operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
    else if (operation->add_type == ABSOLUTE)
        operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
}

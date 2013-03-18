/*
** div.c for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02m-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 12:25:16 2013 maxime ginters
** Last update Thu Jan 10 12:44:30 2013 maxime ginters
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return 0;
    return a / b;
}

float decimale_div(int a, int b)
{
    if (b == 0)
        return 0.0f;
    return (float)a / b;
}

void exec_div(t_div* operation)
{
    if (operation->div_type == INTEGER)
        ((t_integer_op*)operation->div_op)->res = integer_div(((t_integer_op*)operation->div_op)->a, ((t_integer_op*)operation->div_op)->b);
    else if (operation->div_type == DECIMALE)
        ((t_decimale_op*)operation->div_op)->res = integer_div(((t_decimale_op*)operation->div_op)->a, ((t_decimale_op*)operation->div_op)->b);

}


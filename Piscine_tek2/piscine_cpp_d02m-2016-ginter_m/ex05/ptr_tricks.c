/*
** ptr_tricks.c for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02m-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 13:21:38 2013 maxime ginters
** Last update Thu Jan 10 13:46:05 2013 maxime ginters
*/

#include <stdlib.h>
#include "ptr_tricks.h"

int get_array_nb_elem(int* ptr1, int* ptr2)
{
    return ptr2 - ptr1;
}

t_whatever* get_struct_ptr(int* member_ptr)
{
   t_whatever* temp;

    temp = malloc(sizeof(t_whatever));

    return (t_whatever*)((member_ptr - (&temp->member - (int*)temp)));
}




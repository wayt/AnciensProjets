/*
** mem_ptr.c for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02m-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 09:34:50 2013 maxime ginters
** Last update Thu Jan 10 10:38:08 2013 maxime ginters
*/

#include <stdlib.h>
#include <string.h>

#include "mem_ptr.h"

void add_str(char* str1, char* str2, char** res)
{
    if ((*res = calloc(strlen(str1) + strlen(str2) + 1, sizeof(char))) == 0)
        return;
    strcpy(*res, str1);
    strcat(*res, str2);
}

void add_str_struct(t_str_op* str_op)
{
    if ((str_op->res = calloc(strlen(str_op->str1) + strlen(str_op->str2) + 1, sizeof(char))) == 0)
        return;
    strcpy(str_op->res, str_op->str1);
    strcat(str_op->res, str_op->str2);
}

/*
** func_ptr.c for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02m-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 10:56:01 2013 maxime ginters
** Last update Thu Jan 10 11:33:40 2013 maxime ginters
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "func_ptr.h"

void print_normal(char* str)
{
    printf("%s\n", str);
}

void print_reverse(char* str)
{
    int end;

    end = strlen(str);
    while (--end >= 0)
        write(1, str + end, 1);
    write(1, "\n", 1);
}

void print_upper(char* str)
{
    int i;
    char c;

    for (i = 0; str[i]; ++i)
    {
        c = toupper(str[i]);
        write(1, &c, 1);
    }
    write(1, "\n", 1);
}

void print_42(char* str)
{
    (void)str;
    write(1, "42\n", 3);
}

void do_action(t_action action, char* str)
{
    if (action > PRINT_42)
        return;

    void (*array[])(char*) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };
    (array)[action](str);
}

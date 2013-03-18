/*
** new.c for ex_01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_rush1-2016-ginter_m/ex_01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 12 13:06:46 2013 maxime ginters
** Last update Sat Jan 12 14:45:44 2013 vincent leroy
*/

#include <string.h>
#include <stdlib.h>
#include "raise.h"
#include "new.h"

void* new(Class* class)
{
    void* new = NULL;

    if (class == NULL) {
	return (NULL);
    }

    if ((new = malloc(class->__size__)) == NULL)
        raise("Out of memory");
    memcpy(new, class, class->__size__);
    (((Class*)new)->__init__)(new);
    return new;
}

void delete(Object* ptr)
{
    if (ptr == NULL) {
	return ;
    }

    (((Class*)ptr)->__del__)(ptr);
    free(ptr);
}

/*
** new.c for ex_04 in /home/leroy_v/Epitech/piscine2013/Rush1/ex_04
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Jan 12 14:51:47 2013 vincent leroy
** Last update Sat Jan 12 21:10:28 2013 maxime ginters
*/

#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "raise.h"

Object *new(Class *class, ...)
{
    Object *new = NULL;
    va_list	ap;

    if (class == NULL) {
	return (NULL);
    }

    if ((new = malloc(class->__size__)) == NULL) {
	raise("Out of memory");
    }
    memcpy(new, class, class->__size__);

    va_start(ap, class);
    (((Class*)new)->__init__)(new, &ap);
    va_end(ap);
    return (new);
}

Object *va_new(Class *class, va_list *ap)
{
    Object *new = NULL;

    if (class == NULL) {
	return (NULL);
    }

    if ((new = malloc(class->__size__)) == NULL) {
	raise("Out of memory");
    }
    memcpy(new, class, class->__size__);

    (((Class*)new)->__init__)(new, ap);
    return (new);
}

void	delete(Object *ptr)
{
    if (ptr == NULL) {
	return ;
    }

    if (((Class*)ptr)->__del__)
        (((Class*)ptr)->__del__)(ptr);
    free(ptr);
}

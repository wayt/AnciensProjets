/*
** float.c for ex_04 in /home/leroy_v/Epitech/piscine2013/Rush1/ex_04
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Jan 12 15:07:00 2013 vincent leroy
** Last update Sat Jan 12 16:10:39 2013 vincent leroy
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    char name[200];
    int nb;
} IntClass;

static void Int_ctor(Object* self, va_list *ap)
{
    if (self == NULL || ap == NULL) {
	return ;
    }

    ((IntClass*)self)->nb = va_arg(*ap, int);
}

static void Int_dtor(Object* self)
{
    (void) self;
}

static char const* Int_stor(Object* self)
{
    if (self == NULL) {
	return (NULL);
    }

    snprintf(((IntClass*)self)->name, 200, "<Int (%d)>", ((IntClass*)self)->nb);
    return (((IntClass*)self)->name);
}

static Object* Int_add(const Object *self, const Object *other)
{
    Object *result = new(Int, 0);
    if (result == NULL || self == NULL || other == NULL)
        return NULL;
    if (strcmp(((Class*)self)->__name__, "Int") != 0 ||
	strcmp(((Class*)other)->__name__, "Int") != 0) {
	return (NULL);
    }
    ((IntClass *)result)->nb = ((IntClass *)self)->nb + ((IntClass *)other)->nb;
    return result;
}

static Object* Int_sub(const Object *self, const Object *other)
{
    Object *result = new(Int, 0);
    if (result == NULL || self == NULL || other == NULL)
        return NULL;
    if (strcmp(((Class*)self)->__name__, "Int") != 0 ||
	strcmp(((Class*)other)->__name__, "Int") != 0) {
	return (NULL);
    }
    ((IntClass *)result)->nb = ((IntClass *)self)->nb - ((IntClass *)other)->nb;
    return result;
}

static Object* Int_mul(const Object *self, const Object *other)
{
    Object *result = new(Int, 0);
    if (result == NULL || self == NULL || other == NULL)
        return NULL;
    if (strcmp(((Class*)self)->__name__, "Int") != 0 ||
	strcmp(((Class*)other)->__name__, "Int") != 0) {
	return (NULL);
    }
    ((IntClass *)result)->nb = ((IntClass *)self)->nb * ((IntClass *)other)->nb;
    return result;
}

static Object* Int_div(const Object *self, const Object *other)
{
    Object *result = new(Int, 0);
    if (result == NULL || self == NULL || other == NULL)
        return NULL;
    if (strcmp(((Class*)self)->__name__, "Int") != 0 ||
	strcmp(((Class*)other)->__name__, "Int") != 0) {
	return (NULL);
    }
    if (((IntClass *)other)->nb == 0)
        return NULL;
    ((IntClass *)result)->nb = ((IntClass *)self)->nb / ((IntClass *)other)->nb;
    return result;
}

static bool Int_eq(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL)
        return false;
    if (strcmp(((Class*)self)->__name__, "Int") != 0 ||
	strcmp(((Class*)other)->__name__, "Int") != 0) {
	return (false);
    }
    if ( ((IntClass *)self)->nb == ((IntClass *)other)->nb )
        return true;
    return false;
}

static bool Int_gt(const Object* self, const Object *other)
{
    if (self == NULL || other == NULL)
        return false;
    if (strcmp(((Class*)self)->__name__, "Int") != 0 ||
	strcmp(((Class*)other)->__name__, "Int") != 0) {
	return (false);
    }
    if ( ((IntClass *)self)->nb > ((IntClass *)other)->nb )
        return true;
    return false;
}

static bool Int_lt(const Object* self, const Object *other)
{
    if (self == NULL || other == NULL)
        return false;
    if (strcmp(((Class*)self)->__name__, "Int") != 0 ||
	strcmp(((Class*)other)->__name__, "Int") != 0) {
	return (false);
    }
    if ( ((IntClass *)self)->nb < ((IntClass *)other)->nb )
        return true;
    return false;
}

static IntClass _description = {
    { sizeof(IntClass), "Int", &Int_ctor, &Int_dtor, &Int_stor, &Int_add, &Int_sub, &Int_mul, &Int_div, &Int_eq, &Int_gt, &Int_lt },
    {},
    0
};

Class* Int = (Class*) &_description;

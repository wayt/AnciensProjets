/*
** float.c for ex_04 in /home/leroy_v/Epitech/piscine2013/Rush1/ex_04
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Jan 12 15:07:00 2013 vincent leroy
** Last update Sat Jan 12 16:10:53 2013 vincent leroy
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class base;
    char name[200];
    float nb;
} FloatClass;

static void Float_ctor(Object* self, va_list *ap)
{
    if (self == NULL || ap == NULL) {
	return ;
    }

    ((FloatClass*)self)->nb = va_arg(*ap, double);
}

static void Float_dtor(Object* self)
{
    (void) self;
}

static char const* Float_stor(Object* self)
{
    if (self == NULL) {
	return (NULL);
    }

    snprintf(((FloatClass*)self)->name, 200, "<Float (%f)>", ((FloatClass*)self)->nb);
    return (((FloatClass*)self)->name);
}

static Object* Float_add(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (NULL);
    }
    if (strcmp(((Class*)self)->__name__, "Float") != 0 ||
	strcmp(((Class*)other)->__name__, "Float") != 0) {
	return (NULL);
    }

    float nb = ((FloatClass*)self)->nb + ((FloatClass*)other)->nb;
    return (new(Float, nb));
}

static Object* Float_sub(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (NULL);
    }
    if (strcmp(((Class*)self)->__name__, "Float") != 0 ||
	strcmp(((Class*)other)->__name__, "Float") != 0) {
	return (NULL);
    }

    float nb = ((FloatClass*)self)->nb - ((FloatClass*)other)->nb;
    return (new(Float, nb));
}

static Object* Float_mul(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (NULL);
    }
    if (strcmp(((Class*)self)->__name__, "Float") != 0 ||
	strcmp(((Class*)other)->__name__, "Float") != 0) {
	return (NULL);
    }

    float nb = ((FloatClass*)self)->nb * ((FloatClass*)other)->nb;
    return (new(Float, nb));
}

static Object* Float_div(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (NULL);
    }
    if (strcmp(((Class*)self)->__name__, "Float") != 0 ||
	strcmp(((Class*)other)->__name__, "Float") != 0) {
	return (NULL);
    }

    if (((FloatClass*)other)->nb == 0) {
	return (NULL);
    }
    float nb = ((FloatClass*)self)->nb / ((FloatClass*)other)->nb;
    return (new(Float, nb));
}

static bool Float_eq(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (false);
    }
    if (strcmp(((Class*)self)->__name__, "Float") != 0 ||
	strcmp(((Class*)other)->__name__, "Float") != 0) {
	return (false);
    }

    return (((FloatClass*)self)->nb == ((FloatClass*)other)->nb);
}

static bool Float_gt(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (false);
    }
    if (strcmp(((Class*)self)->__name__, "Float") != 0 ||
	strcmp(((Class*)other)->__name__, "Float") != 0) {
	return (false);
    }

    return (((FloatClass*)self)->nb > ((FloatClass*)other)->nb);
}

static bool Float_lt(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (false);
    }
    if (strcmp(((Class*)self)->__name__, "Float") != 0 ||
	strcmp(((Class*)other)->__name__, "Float") != 0) {
	return (false);
    }

    return (((FloatClass*)self)->nb < ((FloatClass*)other)->nb);
}

static FloatClass _description = {
    { sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor, &Float_stor, &Float_add, &Float_sub, &Float_mul, &Float_div, &Float_eq, &Float_gt, &Float_lt },
    {}, 0.0f
};

Class* Float = (Class*) &_description;

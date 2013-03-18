/*
** char.c for ex_04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_rush1-2016-ginter_m/ex_04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 12 16:03:33 2013 maxime ginters
** Last update Sat Jan 12 16:42:05 2013 maxime ginters
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char name[200];
    char c;
} CharClass;

static void Char_ctor(Object* self, va_list *ap)
{
    if (self == NULL || ap == NULL) {
        return ;
    }

    ((CharClass*)self)->c = (char)va_arg(*ap, int);
}

static void Char_dtor(Object* self)
{
    (void) self;
}

static char const* Char_stor(Object* self)
{
    if (self == NULL) {
        return (NULL);
    }

    snprintf(((CharClass*)self)->name, 200, "<Char (%c)>", ((CharClass*)self)->c);
    return (((CharClass*)self)->name);
}

static Object* Char_add(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
        return (NULL);
    }
    if (strcmp(((Class*)self)->__name__, "Char") != 0 ||
        strcmp(((Class*)other)->__name__, "Char") != 0) {
        return (NULL);
    }

    char c = ((CharClass*)self)->c + ((CharClass*)other)->c;
    return (new(Char, c));
}

static Object* Char_sub(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
        return (NULL);
    }
    if (strcmp(((Class*)self)->__name__, "Char") != 0 ||
        strcmp(((Class*)other)->__name__, "Char") != 0) {
        return (NULL);
    }

    char c = ((CharClass*)self)->c - ((CharClass*)other)->c;
    return (new(Char, c));
}

static Object* Char_mul(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
        return (NULL);
    }
    if (strcmp(((Class*)self)->__name__, "Char") != 0 ||
        strcmp(((Class*)other)->__name__, "Char") != 0) {
        return (NULL);
    }

    char c = ((CharClass*)self)->c * ((CharClass*)other)->c;
    return (new(Char, c));
}

static Object* Char_div(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (NULL);
    }
    if (strcmp(((Class*)self)->__name__, "Char") != 0 ||
	strcmp(((Class*)other)->__name__, "Char") != 0) {
	return (NULL);
    }

    if (((CharClass*)other)->c == 0) {
	return (NULL);
    }
    char c = ((CharClass*)self)->c / ((CharClass*)other)->c;
    return (new(Char, c));
}

static bool Char_eq(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (false);
    }
    if (strcmp(((Class*)self)->__name__, "Char") != 0 ||
	strcmp(((Class*)other)->__name__, "Char") != 0) {
	return (false);
    }

    return (((CharClass*)self)->c == ((CharClass*)other)->c);
}

static bool Char_gt(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (false);
    }
    if (strcmp(((Class*)self)->__name__, "Char") != 0 ||
	strcmp(((Class*)other)->__name__, "Char") != 0) {
	return (false);
    }

    return (((CharClass*)self)->c > ((CharClass*)other)->c);
}

static bool Char_lt(const Object *self, const Object *other)
{
    if (self == NULL || other == NULL) {
	return (false);
    }
    if (strcmp(((Class*)self)->__name__, "Char") != 0 ||
	strcmp(((Class*)other)->__name__, "Char") != 0) {
	return (false);
    }

    return (((CharClass*)self)->c < ((CharClass*)other)->c);
}

static CharClass _description = {
    { sizeof(CharClass), "Char", &Char_ctor, &Char_dtor, &Char_stor, &Char_add, &Char_sub, &Char_mul, &Char_div, &Char_eq, &Char_gt, &Char_lt },
    {}, 0
};

Class* Char = (Class*) &_description;

/*
** point.c for ex_02 in /home/leroy_v/Epitech/piscine2013/Rush1/ex_02
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Jan 12 13:50:19 2013 vincent leroy
** Last update Sat Jan 12 15:33:38 2013 maxime ginters
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raise.h"
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    char name[200];
    int x, y;
} PointClass;

static void Point_ctor(Object* self, va_list *ap)
{
    if (self == NULL || ap == NULL) {
	return ;
    }

    ((PointClass*)self)->x = va_arg(*ap, int);
    ((PointClass*)self)->y = va_arg(*ap, int);
}

static void Point_dtor(Object* self)
{
    (void) self;
}

static char const* Point_stor(Object* self)
{
    if (self == NULL) {
	return (NULL);
    }

    snprintf(((PointClass*)self)->name, 200, "<Point (%d, %d)>", ((PointClass*)self)->x, ((PointClass*)self)->y);
    return ((const char*)((PointClass*)self)->name);
}

static Object *Point_add(const Object *self, const Object *other)
{
    Object *result = new(Point, 0, 0);
    if (result == NULL || self == NULL || other == NULL)
        return NULL;
    if (strcmp(((PointClass *)self)->base.__name__, "Point") != 0 || strcmp(((PointClass *)other)->base.__name__, "Point") != 0)
        return NULL;
    ((PointClass *)result)->x = ((PointClass *)self)->x + ((PointClass *)other)->x;
    ((PointClass *)result)->y = ((PointClass *)self)->y + ((PointClass *)other)->y;
    return result;
}

static Object *Point_sub(const Object *self, const Object *other)
{
    Object *result = new(Point, 0, 0);
    if (result == NULL || self == NULL || other == NULL)
        return NULL;
    if (strcmp(((PointClass *)self)->base.__name__, "Point") != 0 || strcmp(((PointClass *)other)->base.__name__, "Point") != 0)
        return NULL;
    ((PointClass *)result)->x = ((PointClass *)self)->x - ((PointClass *)other)->x;
    ((PointClass *)result)->y = ((PointClass *)self)->y - ((PointClass *)other)->y;
    return result;
}

static PointClass _description = {
    { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_stor, &Point_add, &Point_sub },
    {}, 0, 0
};

Class* Point = (Class*) &_description;

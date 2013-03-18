/*
** point.c for ex_02 in /home/leroy_v/Epitech/piscine2013/Rush1/ex_02
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Jan 12 13:50:19 2013 vincent leroy
** Last update Sat Jan 12 15:27:53 2013 maxime ginters
*/

#include <stdio.h>
#include <stdlib.h>
#include "raise.h"
#include "point.h"

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

static PointClass _description = {
    { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_stor },
    {}, 0, 0
};

Class* Point = (Class*) &_description;

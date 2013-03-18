/*
** vertex.c for ex_02 in /home/leroy_v/Epitech/piscine2013/Rush1/ex_02
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Jan 12 13:50:19 2013 vincent leroy
** Last update Sat Jan 12 15:28:00 2013 maxime ginters
*/

#include <stdio.h>
#include <stdlib.h>
#include "raise.h"
#include "vertex.h"

typedef struct
{
    Class base;
    char name[200];
    int x, y, z;
} VertexClass;

static void Vertex_ctor(Object* self, va_list *ap)
{
    if (self == NULL || ap == NULL) {
	return ;
    }

    ((VertexClass*)self)->x = va_arg(*ap, int);
    ((VertexClass*)self)->y = va_arg(*ap, int);
    ((VertexClass*)self)->z = va_arg(*ap, int);
}

static void Vertex_dtor(Object* self)
{
    (void) self;
}

static char const* Vertex_stor(Object* self)
{
    if (self == NULL) {
	return (NULL);
    }

    snprintf(((VertexClass*)self)->name, 200, "<Vertex (%d, %d, %d)>", ((VertexClass*)self)->x, ((VertexClass*)self)->y, ((VertexClass*)self)->z);
    return ((const char*)((VertexClass*)self)->name);
}

static VertexClass _description = {
    { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_stor },
    {}, 0, 0, 0
};

Class* Vertex = (Class*) &_description;

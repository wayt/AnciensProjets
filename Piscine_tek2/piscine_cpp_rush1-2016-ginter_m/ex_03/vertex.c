/*
** vertex.c for ex_02 in /home/leroy_v/Epitech/piscine2013/Rush1/ex_02
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Jan 12 13:50:19 2013 vincent leroy
** Last update Sat Jan 12 15:34:56 2013 maxime ginters
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new.h"
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

static Object* Vertex_add(const Object* self, const Object* other)
{
    if (!self || !other)
        return NULL;
    if (strcmp(((VertexClass*)self)->base.__name__, "Vertex") != 0 ||
        strcmp(((VertexClass*)other)->base.__name__, "Vertex") != 0)
        return NULL;
    int x, y, z;
    x = ((VertexClass*)self)->x + ((VertexClass*)other)->x;
    y = ((VertexClass*)self)->y + ((VertexClass*)other)->y;
    z = ((VertexClass*)self)->z + ((VertexClass*)other)->z;
    return new(Vertex, x, y, z);
}

static Object* Vertex_sub(const Object* self, const Object* other)
{
    if (!self || !other)
        return NULL;
    if (strcmp(((VertexClass*)self)->base.__name__, "Vertex") != 0 ||
        strcmp(((VertexClass*)other)->base.__name__, "Vertex") != 0)
        return NULL;
    int x, y, z;
    x = ((VertexClass*)self)->x - ((VertexClass*)other)->x;
    y = ((VertexClass*)self)->y - ((VertexClass*)other)->y;
    z = ((VertexClass*)self)->z - ((VertexClass*)other)->z;
    return new(Vertex, x, y, z);
}

static VertexClass _description = {
    { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_stor, &Vertex_add, &Vertex_sub },
    {}, 0, 0, 0
};

Class* Vertex = (Class*) &_description;

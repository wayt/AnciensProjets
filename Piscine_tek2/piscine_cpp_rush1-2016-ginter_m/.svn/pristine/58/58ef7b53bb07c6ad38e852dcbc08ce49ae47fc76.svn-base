
#include <stdlib.h>
#include <stdarg.h>

#include "raise.h"
#include "array.h"
#include "new.h"


typedef struct
{
    Container base;
    Class* _type;
    size_t _size;
    Object** _tab;
} ArrayClass;

typedef struct {
    Iterator base;
    ArrayClass* _array;
    size_t _idx;
} ArrayIteratorClass;

void ArrayIterator_ctor(ArrayIteratorClass* self, va_list* args)
{
    self->_idx = va_arg(*args, size_t);
    self->_array = (ArrayClass*)va_arg(*args, void*);
}

bool ArrayIterator_eq(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
    if (!self || !other)
        return false;
    return self->_idx == other->_idx;
}

bool ArrayIterator_gt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
    if (!self || !other)
        return false;
    return self->_idx > other->_idx;
}

bool ArrayIterator_lt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
    if (!self || !other)
        return false;
    return self->_idx < other->_idx;
}

void ArrayIterator_incr(ArrayIteratorClass* self)
{
    self->_idx++;
}

Object* ArrayIterator_getval(ArrayIteratorClass* self)
{
    if (!self)
        return NULL;
    return (((Container*)(self->_array))->__getitem__)((Container*)self->_array, self->_idx);
}

void ArrayIterator_setval(ArrayIteratorClass* self, ...)
{
    va_list list;
    va_start(list, self);
    if (self->_idx >= self->_array->_size)
        return;
    if (self->_array->_tab[self->_idx])
        delete(self->_array->_tab[self->_idx]);
    self->_array->_tab[self->_idx] = va_new(self->_array->_type, &list);
    va_end(list);
}

static ArrayIteratorClass ArrayIteratorDescr = {
    {
        {
            sizeof(ArrayIteratorClass), "ArrayIterator",
            (ctor_t) &ArrayIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ArrayIterator_eq,
            (binary_comparator_t) &ArrayIterator_gt,
            (binary_comparator_t) &ArrayIterator_lt,
        },
        (incr_t) &ArrayIterator_incr,
        (getval_t) &ArrayIterator_getval,
        (setval_t) &ArrayIterator_setval,
    },
    NULL,
    0
};

static Class* ArrayIterator = (Class*) &ArrayIteratorDescr;

void Array_ctor(ArrayClass* self, va_list* args)
{
   if (self == NULL)
       return;
   self->_size = va_arg(*args, unsigned int);
   self->_type = (Class *)va_arg(*args, void *);
   self->_tab = malloc(sizeof(Object *) * self->_size);

   size_t i;
   for (i = 0; i < self->_size; i++)
   {
       va_list newArg;
       va_copy(newArg, *args);
       self->_tab[i] = va_new(self->_type, &newArg);
   }
}

void Array_dtor(ArrayClass* self)
{
    (void)self;
    if (self->_tab)
    {
        size_t i;
        for (i = 0; i < self->_size; i++)
            if (self->_tab[i])
                delete(self->_tab[i]);
        free(self->_tab);
        self->_tab = NULL;
    }
}

size_t Array_len(ArrayClass* self)
{
    return self->_size;
}

Iterator* Array_begin(ArrayClass* self)
{
    if (!self)
        return NULL;
    return new(ArrayIterator, 0, self);
}

Iterator* Array_end(ArrayClass* self)
{
    if (!self)
        return NULL;
    return new(ArrayIterator, self->_size, self);

}

Object* Array_getitem(ArrayClass* self, ...)
{
    va_list list;
    va_start(list, self);
    size_t i = va_arg(list, size_t);
    va_end(list);
    if (i >= self->_size)
        return NULL;
    return self->_tab[i];
}

void Array_setitem(ArrayClass* self, ...)
{
    va_list list;
    va_start(list, self);
    size_t i = va_arg(list, size_t);
    if (i >= self->_size)
        return;
    if (self->_tab[i])
        delete(self->_tab[i]);
    self->_tab[i] = va_new(self->_type, &list);
    va_end(list);
}

void Array_resize(ArrayClass* self, ...)
{
    if (!self)
        return;
    va_list list;

    va_start(list, self);
    size_t size = va_arg(list, size_t);
    if (size != self->_size)
    {
        if (size < self->_size)
        {
            for (size_t i = size; i < self->_size; ++i)
                delete(self->_tab[i]);
            self->_tab = realloc(self->_tab, size * sizeof(Object*));
        }
        else
        {
            self->_tab = realloc(self->_tab, size * sizeof(Object*));
            for (size_t i = self->_size; i < size; ++i)
            {
                va_list newArg;
                va_copy(newArg, list);
                self->_tab[i] = va_new(self->_type, &newArg);
            }
        }
        self->_size = size;
    }
    va_end(list);
}

void Array_push_back(ArrayClass *self, ...)
{
    if (!self)
	return;
    va_list arg;
    va_start(arg, self);
    self->_tab = realloc(self->_tab, (self->_size + 1) * sizeof(Object*));
    self->_tab[self->_size] = va_new(self->_type, &arg);
    self->_size++;
    printf("toto\n");
    va_end(arg);
}

static ArrayClass _descr = {
    { /* Container */
        { /* Class */
	    sizeof(ArrayClass), "Array",
            (ctor_t) &Array_ctor, (dtor_t) &Array_dtor,
            NULL, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &Array_len,
        (iter_t) &Array_begin,
        (iter_t) &Array_end,
        (getitem_t) &Array_getitem,
        (setitem_t) &Array_setitem,
        (resize_t)  &Array_resize,
	(pushback_t) &Array_push_back
    },
    NULL, 0, NULL
};

Class* Array = (Class*) &_descr;


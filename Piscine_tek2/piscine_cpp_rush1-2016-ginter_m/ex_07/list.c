
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct s_Item
{
    struct s_Item *next;
    Object *obj;
} Item;

typedef struct
{
    Container base;
    Class* _type;
    Item *list;
} ListClass;

typedef struct {
    Iterator base;
    ListClass* _list;
    size_t _idx;
} ListIteratorClass;

void ListIterator_ctor(ListIteratorClass* self, va_list* args)
{
    if (self == NULL || args == NULL) {
	return ;
    }
    self->_idx = va_arg(*args, unsigned int);
    self->_list = (ListClass*)va_arg(*args, void *);
}

bool ListIterator_eq(ListIteratorClass* self, ListIteratorClass* other)
{
    if (self == NULL || other == NULL) {
	return (false);
    }
    return self->_idx - other->_idx;
}

bool ListIterator_gt(ListIteratorClass* self, ListIteratorClass* other)
{
    if (self == NULL || other == NULL) {
	return (false);
    }
    return self->_idx > other->_idx;
}

bool ListIterator_lt(ListIteratorClass* self, ListIteratorClass* other)
{
    if (self == NULL || other == NULL) {
	return (false);
    }
    return self->_idx < other->_idx;
}

void ListIterator_incr(ListIteratorClass* self)
{
    if (self == NULL) {
	return ;
    }
    self->_idx++;
}

Object* ListIterator_getval(ListIteratorClass* self)
{
    if (self == NULL) {
	return (NULL);
    }
    size_t i = 0;
    Item* it = NULL;
    for (it = self->_list->list; it != NULL; it = it->next)
    {
        if(i == self->_idx)
        {
            return it->obj;
        }
	i++;
    }
    return NULL;
}

void ListIterator_setval(ListIteratorClass* self, ...)
{
    if (self == NULL) {
	return ;
    }
    size_t i = 0;
    Item *it;
    va_list ap;

    va_start(ap, self);

    for (it = self->_list->list; it != NULL; it = it->next)
    {
        if(i == self->_idx)
        {
            delete(it->obj);
            it->obj = va_new(self->_list->_type, &ap);
            va_end(ap);
            return ;
        }
        i++;
    }
    va_end(ap);
}

static ListIteratorClass ListIteratorDescr = {
    {
        {
            sizeof(ListIteratorClass), "ListIterator",
            (ctor_t) &ListIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ListIterator_eq,
            (binary_comparator_t) &ListIterator_gt,
            (binary_comparator_t) &ListIterator_lt,
        },
        (incr_t) &ListIterator_incr,
        (getval_t) &ListIterator_getval,
        (setval_t) &ListIterator_setval,
    },
    NULL,
    0
};

static Class* ListIterator = (Class*) &ListIteratorDescr;

void List_vaadditem(ListClass *self, va_list *ap)
{
    if (self == NULL) {
	return ;
    }

    Item *it, *new;

    if ((new = calloc(1, sizeof(Item))) == NULL) {
	raise("Out of memory");
    }
    new->obj = va_new(self->_type, ap);

    for (it = self->list; it != NULL && it->next != NULL; it = it->next);

    if (it == NULL) {
	self->list = new;
    } else {
	it->next = new;
    }
}

void List_ctor(ListClass* self, va_list* args)
{
    if (self == NULL || args == NULL) {
	return ;
    }

    size_t size = va_arg(*args, int);
    if ((self->_type = va_arg(*args, void*)) == NULL) {
	return ;
    }

    for (size_t i = 0; i < size; ++i) {
	va_list newArg;
	va_copy(newArg, *args);
	List_vaadditem(self, &newArg);
    }
}

void List_dtor(ListClass* self)
{
    if (self == NULL) {
	return ;
    }
    Item *it, *next;
    for (it = self->list; it != NULL; it = it->next) {
	delete(it->obj);
    }
    for (it = self->list; it != NULL; it = next) {
	next = it->next;
	free(it);
    }
}

size_t List_len(ListClass* self)
{
    if (self == NULL) {
	return (0);
    }
    size_t len = 0;
    Item *it;
    for (it = self->list; it != NULL; it = it->next)
    {
        len++;
    }
    return len;
}

Iterator* List_begin(ListClass* self)
{
    if (self == NULL) {
	return (NULL);
    }
    return new(ListIterator, 0, self);
}

Iterator* List_end(ListClass* self)
{
    if (self == NULL) {
	return (NULL);
    }
    return new(ListIterator, List_len(self), self);
}

Object* List_getitem(ListClass* self, ...)
{
    if (self == NULL) {
	return (NULL);
    }
    int i = 0;
    int id;
    Item *it;
    va_list ap;

    va_start(ap, self);
    id = va_arg(ap, int);
    va_end(ap);

    for (it = self->list; it != NULL; it = it->next)
    {
        if(i == id)
        {
            return it->obj;
        }
	i++;
    }
    return NULL;
}


void List_setitem(ListClass* self, ...)
{
    if (self == NULL) {
	return ;
    }
    int i = 0;
    int id;
    Item *it;
    va_list ap;

    va_start(ap, self);
    id = va_arg(ap, int);

    for (it = self->list; it != NULL; it = it->next)
    {
        if(i == id)
        {
            delete(it->obj);
            it->obj = va_new(self->_type, &ap);
            va_end(ap);
            return ;
        }
        i++;
    }
    va_end(ap);
}

void List_additem(ListClass *self, ...)
{
    if (self == NULL) {
	return ;
    }

    Item *it, *new;
    va_list ap;

    if ((new = calloc(1, sizeof(Item))) == NULL) {
	raise("Out of memory");
    }
    va_start(ap, self);
    new->obj = va_new(self->_type, &ap);
    va_end(ap);

    for (it = self->list; it != NULL && it->next != NULL; it = it->next);

    if (it == NULL) {
	self->list = new;
    } else {
	it->next = new;
    }
}

void List_pushfront(ListClass *self, ...)
{
    if (self == NULL) {
	return ;
    }

    Item *new;
    va_list ap;

    if ((new = calloc(1, sizeof(Item))) == NULL) {
	raise("Out of memory");
    }
    va_start(ap, self);
    new->obj = va_new(self->_type, &ap);
    va_end(ap);

    new->next = self->list;
    self->list = new;
}

char const *List_aff(Object *obj)
{
    ListClass *this = obj;
    Item *it;
    char *str = calloc(8, sizeof(char));

    strcpy(str, "List { ");
    for (it = this->list; it != NULL; it = it->next) {
	str = realloc(str, strlen(str(it->obj)) + strlen(str) + 3);
	strcat(str, str(it->obj));
	strcat(str, " ");
    }
    strcat(str, "}");
    return (str);
}

void List_popfront(ListClass *self)
{
    if (self == NULL || self->list == NULL)
	return ;
    Item *next;
    next = self->list->next;
    delete(self->list->obj);
    free(self->list);
    self->list = next;
}

void List_popback(ListClass *self)
{
    Item *li;
    Item *prev = NULL;
    if (self == NULL || self->list == NULL)
	return ;
    for(li = self->list; li != NULL && li->next != NULL; prev = li, li = li->next);
    if (prev != NULL)
    {
	prev->next = NULL;
	delete(li->obj);
	free(li);
    }
    else if (li != NULL)
    {
	delete(li->obj);
	free(li);
	self->list = NULL;
    }
}

static ListClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ListClass), "List",
            (ctor_t) &List_ctor, (dtor_t) &List_dtor,
            &List_aff, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &List_len,
        (iter_t) &List_begin,
        (iter_t) &List_end,
        (getitem_t) &List_getitem,
        (setitem_t) &List_setitem,
	(setitem_t) &List_additem,
	(setitem_t) &List_pushfront,
	(setitem_t) &List_additem,
	(popitem_t) &List_popfront,
	(popitem_t) &List_popback
    },
    NULL, NULL
};

Class* List = (Class*) &_descr;

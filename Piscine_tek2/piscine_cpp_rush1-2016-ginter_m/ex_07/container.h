
#ifndef CONTAINER_H
# define CONTAINER_H

# include "object.h"
# include "iterator.h"

typedef struct Container_s Container;

typedef Iterator* (*iter_t)(Container* self);
typedef size_t (*len_t)(Container* self);
typedef Object* (*getitem_t)(Container* self, ...);
typedef void (*setitem_t)(Container* self, ...);
typedef void (*popitem_t)(Container* self);

struct Container_s {
    Class base;
    len_t       __len__;
    iter_t      __begin__;
    iter_t      __end__;
    getitem_t   __getitem__;
    setitem_t   __setitem__;
    setitem_t	__additem__;
    setitem_t	__pushfitem__;
    setitem_t	__pushbitem__;
    popitem_t   __popfitem__;
    popitem_t   __popbitem__;
};

# define len(c)                 (((Container*) c)->__len__(c))
# define begin(c)               (((Container*) c)->__begin__(c))
# define end(c)                 (((Container*) c)->__end__(c))
# define getitem(c, ...)        (((Container*) c)->__getitem__(c, __VA_ARGS__))
# define setitem(c, ...)        (((Container*) c)->__setitem__(c, __VA_ARGS__))
# define additem(c, ...)        (((Container*) c)->__additem__(c, __VA_ARGS__))
# define push_front(c, ...)      (((Container*) c)->__pushfitem__(c, __VA_ARGS__))
# define push_back(c, ...)      (((Container*) c)->__pushbitem__(c, __VA_ARGS__))
# define pop_front(c)      (((Container*) c)->__popfitem__(c))
# define pop_back(c)      (((Container*) c)->__popbitem__(c))

#endif


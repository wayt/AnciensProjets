/*
** main.c for ex_06 in /home/leroy_v/Epitech/piscine2013/Rush1/ex_06
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Jan 12 18:25:32 2013 vincent leroy
** Last update Sat Jan 12 23:52:00 2013 vincent leroy
*/

#include <stdlib.h>
#include <stdio.h>
#include "new.h"
#include "list.h"
#include "int.h"
#include "iterator.h"

int main()
{
    Object *obj = new(List, 10, Int, 42);
    additem(obj, 10);
    setitem(obj, 0, 84);
    printf("%s\n", str(obj));
    pop_front(obj);
    pop_back(obj);
    printf("%s\n", str(obj));
    push_front(obj, 100);
    push_back(obj, 200);
    printf("%s\n", str(obj));
    Object *obj2 = getitem(obj, 1);
    printf("obj2 : %s\n", str(obj2));
    Iterator *it = begin(obj), *e = end(obj);

    while (lt(it, e)) {
	printf("%s\n", str(getval(it)));
	incr(it);
    }
    delete(obj);
    return (0);
}

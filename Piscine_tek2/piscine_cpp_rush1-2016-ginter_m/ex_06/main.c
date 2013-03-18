/*
** main.c for ex_06 in /home/leroy_v/Epitech/piscine2013/Rush1/ex_06
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Jan 12 18:25:32 2013 vincent leroy
** Last update Sat Jan 12 22:36:20 2013 vincent leroy
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
    Object *obj2 = getitem(obj, 1);
    Iterator *it = begin(obj);

    while (lt(it, end(obj))) {
	printf("%s\n", str(getval(it)));
	incr(it);
    }
    printf("%s\n", str(obj));
    printf("%s\n", str(obj2));
    return (0);
}

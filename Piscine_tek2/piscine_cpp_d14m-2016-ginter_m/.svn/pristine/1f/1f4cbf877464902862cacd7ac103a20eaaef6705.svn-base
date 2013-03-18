/*
** FruitBox.cpp for piscine_cpp_d14m-2016-ginter_m in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d14m-2016-ginter_m
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 22 14:28:10 2013 maxime ginters
** Last update Tue Jan 22 14:41:34 2013 maxime ginters
*/

#include "FruitBox.h"

FruitNode::FruitNode(Fruit* d, FruitNode* n)
{
    data = d;
    next = n;
}

FruitBox::FruitBox(int size) :
    _node(NULL), _size(size)
{}

int FruitBox::nbFruits() const
{
    int count = 0;
    for (FruitNode* node = _node; node != NULL; node = node->next)
        ++count;
    return count;
}

bool FruitBox::putFruit(Fruit* f)
{
    int count = 0;
    FruitNode* node = _node;
    if (node)
        for (; node != NULL && node->next != NULL; node = node->next)
        {
            if (++count > _size)
                return false;
            if (node->data == f)
                return false;
        }
    if (node)
        node->next = new FruitNode(f, NULL);
    else
        node = new FruitNode(f, NULL);
    return true;
}

Fruit* FruitBox::pickFruit()
{
    return _node ? _node->data : NULL;
}

FruitNode* FruitBox::head()
{
    return _node;
}


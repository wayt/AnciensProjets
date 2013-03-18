/*
** FruitBox.h for piscine_cpp_d14m-2016-ginter_m in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d14m-2016-ginter_m
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 22 14:25:32 2013 maxime ginters
** Last update Tue Jan 22 14:37:56 2013 maxime ginters
*/

#ifndef FRUITBOX_H_
# define FRUITBOX_H_

#include "Fruit.h"

struct FruitNode
{
    FruitNode(Fruit* d, FruitNode* n);
    Fruit* data;
    FruitNode* next;
};

class FruitBox
{
public:
    FruitBox(int size);
    int nbFruits() const;
    bool putFruit(Fruit* f);
    Fruit* pickFruit();
    FruitNode* head();
private:
    FruitNode* _node;
    int _size;
};

#endif /* !FRUITBOX_H_ */

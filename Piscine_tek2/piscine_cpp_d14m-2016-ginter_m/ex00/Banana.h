/*
** Banana.h for piscine_cpp_d14m-2016-ginter_m in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d14m-2016-ginter_m
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 22 14:22:02 2013 maxime ginters
** Last update Tue Jan 22 14:24:32 2013 maxime ginters
*/

#ifndef BANANA_H_
# define BANANA_H_

#include "Fruit.h"

class Banana : public Fruit
{
public:
    explicit Banana(int vitamin = 5);
    virtual ~Banana();
};

#endif /* !BANANA_H_ */

/*
** IElf.h for piscine_cpp_rush2-2016-leroy_v in /home/fest/Epitech/Piscine_tek2/piscine_cpp_rush2-2016-leroy_v
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 22:40:21 2013 maxime ginters
** Last update Sat Jan 19 23:18:50 2013 maxime ginters
*/

#ifndef IELF_H_
# define IELF_H_

#include "TablePePeNoel.h"
#include "ConveyorBeltPePeNoel.h"

class IElf
{
public:
    virtual ~IElf() {}
    virtual void PrepareToWork(TablePePeNoel* table, ConveyorBeltPePeNoel* conveyor) = 0;
    virtual Object* TakeNewToy() = 0;
    virtual void Work() = 0;
};

#endif /* !IELF_H_ */

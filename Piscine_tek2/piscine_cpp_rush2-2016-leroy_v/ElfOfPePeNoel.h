/*
** ElfOfPePeNoel.h for piscine_cpp_rush2-2016-leroy_v in /home/fest/Epitech/Piscine_tek2/piscine_cpp_rush2-2016-leroy_v
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 23:11:04 2013 maxime ginters
** Last update Sun Jan 20 02:25:40 2013 maxime ginters
*/

#ifndef ELFOFPEPENOEL_H_
# define ELFOFPEPENOEL_H_

#include <cstdlib>
#include "TablePePeNoel.h"
#include "ConveyorBeltPePeNoel.h"
#include "Object.h"
#include "Toy.h"
#include "Teddy.h"
#include "SexToy.h"
#include "LittlePoney.h"
#include "IElf.h"

class ElfOfPePeNoel : public IElf
{
public:
    explicit ElfOfPePeNoel();
    virtual ~ElfOfPePeNoel();

    void PrepareToWork(TablePePeNoel* table, ConveyorBeltPePeNoel* conveyor);
    Object* TakeNewToy();
    void Work();

private:
    void PutOnTable(Object*& obj);
    bool canWork() const;
    TablePePeNoel* _table;
    ConveyorBeltPePeNoel* _conveyor;
};

#endif /* !ELFOFPEPENOEL_H_ */

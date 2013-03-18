/*
** ElfOfPePeNoel.cpp for piscine_cpp_rush2-2016-leroy_v in /home/fest/Epitech/Piscine_tek2/piscine_cpp_rush2-2016-leroy_v
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 23:18:57 2013 maxime ginters
** Last update Sun Jan 20 05:32:34 2013 maxime ginters
*/

#include <iostream>
#include "ElfOfPePeNoel.h"

ElfOfPePeNoel::ElfOfPePeNoel() :
    _table(NULL), _conveyor(NULL)
{
}

ElfOfPePeNoel::~ElfOfPePeNoel()
{
}

void ElfOfPePeNoel::PrepareToWork(TablePePeNoel* table, ConveyorBeltPePeNoel* conveyor)
{
    if (canWork())
    {
        std::cout << ELFOFPEPENOEL_STILL_INSTALLED << std::endl;
        return;
    }
    _table = table;
    _conveyor = conveyor;
    std::cout << ELFOFPEPENOEL_INSTALLED << std::endl;
}

Object* ElfOfPePeNoel::TakeNewToy()
{
    if (!canWork())
    {
        std::cout << ELFOFPEPENOEL_CANT_WORK << std::endl;
        return NULL;
    }

    Object* obj = NULL;
    switch (rand() % SUB_TOY_COUNT)
    {
        case TYPE_TEDDY:
            obj = new Teddy();
            break;
        case TYPE_LITTLEPONEY:
            obj = new LittlePoney();
            break;
        case TYPE_SEXTOY:
            obj = new SexToy();
            break;
        default:
            std::cout << "Error: in ElfOfPePeNoel::TakeNewToy()" << std::endl;
            return NULL;
    }
    if (Toy* toy = obj->ToToy())
        toy->isTaken();
    return obj;
}

bool ElfOfPePeNoel::canWork() const
{
    return _table && _conveyor && !_table->isBroken();
}

void ElfOfPePeNoel::PutOnTable(Object*& obj)
{
    if (_table)
        *_table << obj;
    obj = NULL;
}

void ElfOfPePeNoel::Work()
{
    if (!canWork())
    {
        std::cout << ELFOFPEPENOEL_CANT_WORK << std::endl;
        return;
    }

    Object *obj = NULL;
    Object *container = NULL;
    while (canWork())
    {
        _conveyor->IN();
        *_conveyor >> obj;
        if (obj->getSubType() == TYPE_BOX)
        {
            obj->ToBox()->openMe();
            obj->ToBox()->wrapMeThat(TakeNewToy());
            obj->ToBox()->closeMe();
            if ((container = _table->take(1<<TYPE_GIFTPAPER)) != NULL)
            {
                container->ToGiftPaper()->wrapMeThat(obj);
                container->ToGiftPaper()->closeMe();
                *_conveyor << container;
                _conveyor->OUT();
            }
            else
                PutOnTable(obj);
        }
        else if (obj->getSubType() == TYPE_GIFTPAPER)
        {
            if ((container = _table->take(1<<TYPE_BOX)) != NULL)
            {
                obj->ToGiftPaper()->wrapMeThat(container);
                obj->ToGiftPaper()->closeMe();
                *_conveyor << obj;
                _conveyor->OUT();
            }
        }
        else
        {
            std::cout << "Mmmh ?! MacWrap ?! Noam noam noam !!" << std::endl;
        }
    }
}

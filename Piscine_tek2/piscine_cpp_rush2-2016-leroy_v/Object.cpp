/*
** Object.cpp for PapaNoel in /home/vaga/Projects/tek2/piscine/rush2
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sat Jan 19 15:29:30 2013 fabien casters
** Last update Sun Jan 20 02:33:03 2013 maxime ginters
*/

#include <iostream>
#include "Object.h"

Object::Object(ObjectType type, ObjectSubType subtype, const std::string &title) :
    _type(type), _subType(subtype), _title(title)
{

}

void Object::Hello() const
{
    std::cout << "Hello world !" << std::endl;
}

ObjectType Object::getType() const
{
    return _type;
}

ObjectSubType Object::getSubType() const
{
    return _subType;
}

const std::string& Object::getTitle() const
{
    return _title;
}

GiftPaper* Object::ToGiftPaper()
{
    if (_subType != TYPE_GIFTPAPER)
        return NULL;
    return reinterpret_cast<GiftPaper*>(this);
}

Wrap* Object::ToWrap()
{
    if (_type != TYPE_WRAP)
        return NULL;
    return reinterpret_cast<Wrap*>(this);
}

const Wrap* Object::ToWrap() const
{
    if (_type != TYPE_WRAP)
        return NULL;
    return (const Wrap*)((Wrap*)this);
}

Box* Object::ToBox()
{
    if (_subType != TYPE_BOX)
        return NULL;
    return reinterpret_cast<Box*>(this);
}

Toy* Object::ToToy()
{
    if (_type != TYPE_TOY)
        return NULL;
    return reinterpret_cast<Toy*>(this);
}

Teddy* Object::ToTeddy()
{
    if (_subType != TYPE_TEDDY)
        return NULL;
    return reinterpret_cast<Teddy*>(this);
}

LittlePoney* Object::ToLittlePoney()
{
    if (_subType != TYPE_LITTLEPONEY)
        return NULL;
    return reinterpret_cast<LittlePoney*>(this);
}

SexToy* Object::ToSexToy()
{
    if (_subType != TYPE_SEXTOY)
        return NULL;
    return reinterpret_cast<SexToy*>(this);
}

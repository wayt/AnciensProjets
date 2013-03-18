/*
** OperandFactory.cpp for abstractVM in /home/vaga/Projects/tek2/abstractVM
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Wed Feb 13 14:34:15 2013 fabien casters
** Last update Fri Feb 22 12:49:06 2013 fabien casters
*/

#include "OperandFactory.h"
#include "Int8.h"
#include "Int16.h"
#include "Int32.h"
#include "Float.h"
#include "Double.h"

OperandFactory::OperandFactory() : _type()
{
    _operands[TYPE_INT8] = &OperandFactory::createInt8;
    _operands[TYPE_INT16] = &OperandFactory::createInt16;
    _operands[TYPE_INT32] = &OperandFactory::createInt32;
    _operands[TYPE_FLOAT] = &OperandFactory::createFloat;
    _operands[TYPE_DOUBLE] = &OperandFactory::createDouble;
    _type["int8"] = TYPE_INT8;
    _type["int16"] = TYPE_INT16;
    _type["int32"] = TYPE_INT32;
    _type["float"] = TYPE_FLOAT;
    _type["double"] = TYPE_DOUBLE;
}

OperandFactory* OperandFactory::instance()
{
    static OperandFactory* instance = NULL;
    if (!instance)
        instance = new OperandFactory;
    return instance;
}

eOperandType OperandFactory::getType(const std::string &type)
{
    if (_type.find(type) == _type.end())
        throw Exception::ExceptTypeNotFound();
    return _type[type];
}

IOperand *OperandFactory::createOperand(eOperandType type, const std::string &value)
{
    return (this->*_operands[type])(value);
}

IOperand *OperandFactory::createInt8(const std::string &value)
{
    return new Int8(value);
}
IOperand *OperandFactory::createInt16(const std::string &value)
{
    return new Int16(value);
}

IOperand *OperandFactory::createInt32(const std::string &value)
{
    return new Int32(value);
}

IOperand *OperandFactory::createFloat(const std::string &value)
{
    return new Float(value);
}

IOperand *OperandFactory::createDouble(const std::string &value)
{
    return new Double(value);
}

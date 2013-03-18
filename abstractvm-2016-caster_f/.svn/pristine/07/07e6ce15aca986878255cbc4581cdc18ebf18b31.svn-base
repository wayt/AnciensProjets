/*
** OperandFactory.h for abstractVM in /home/vaga/Projects/tek2/abstractVM
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Wed Feb 13 14:21:01 2013 fabien casters
** Last update Tue Feb 19 11:42:20 2013 fabien casters
*/

#ifndef OPERANDFACTORY_H_
# define OPERANDFACTORY_H_

#include <string>
#include <map>

#include "IOperand.h"

class OperandFactory;
typedef IOperand *(OperandFactory::*pCreate)(const std::string &);

class OperandFactory
{
public:
    IOperand *createOperand(eOperandType type, const std::string &value);
    eOperandType getType(const std::string &type);
    static OperandFactory *instance();

private:
    OperandFactory();
    virtual ~OperandFactory() {}
    pCreate _operands[TYPE_COUNT];
    std::map<std::string, eOperandType> _type;
    IOperand *createInt8(const std::string &value);
    IOperand *createInt16(const std::string &value);
    IOperand *createInt32(const std::string &value);
    IOperand *createFloat(const std::string &value);
    IOperand *createDouble(const std::string &value);
};

#define sOperandFactory OperandFactory::instance()

#endif

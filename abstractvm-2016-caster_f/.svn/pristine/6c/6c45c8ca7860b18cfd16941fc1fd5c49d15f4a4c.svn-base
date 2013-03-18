/*
** IOperand.h for abstractVM in /home/vaga/Projects/tek2/abstractVM
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Wed Feb 13 14:10:24 2013 fabien casters
** Last update Thu Feb 21 13:09:46 2013 fabien casters
*/

#ifndef IOPERAND_H_
# define IOPERAND_H_

#include <string>

enum eOperandType
{
    TYPE_INT8   = 0,
    TYPE_INT16  = 1,
    TYPE_INT32  = 2,
    TYPE_FLOAT  = 3,
    TYPE_DOUBLE = 4,
    TYPE_COUNT  = 5
};

class IOperand
{
 public:
    virtual ~IOperand() {}

    virtual IOperand *operator+(const IOperand &rhs) const = 0;
    virtual IOperand *operator-(const IOperand &rhs) const = 0;
    virtual IOperand *operator*(const IOperand &rhs) const = 0;
    virtual IOperand *operator/(const IOperand &rhs) const = 0;
    virtual IOperand *operator%(const IOperand &rhs) const = 0;
    virtual bool operator==(const IOperand &rhs) const = 0;

    virtual std::string const &toString() const = 0;
    virtual int getPrecision() const = 0;
    virtual eOperandType getType() const = 0;
};

#endif


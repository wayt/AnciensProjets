/*
** AOperand.h for Operand in /Storage/Epitech/AbstractVM/Operand
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Feb 15 13:52:29 2013 maxime ginters
** Last update Fri Feb 22 13:45:23 2013 maxime ginters
*/

#ifndef AOPERAND_H_
# define AOPERAND_H_

#include <limits>
#include "OperandFactory.h"
#include "SharedDefines.h"
#include "Exception.h"

class AOperand : public IOperand
{
public:
    AOperand(eOperandType type, int precision, std::string const& value);
    virtual ~AOperand() {}

    std::string const& toString() const;
    int getPrecision() const;
    eOperandType getType() const;

    static int64 toInt64(std::string const& str);
    static ld64 toLd64(std::string const& str);

    IOperand *operator+(const IOperand &rhs) const;
    IOperand *operator-(const IOperand &rhs) const;
    IOperand *operator*(const IOperand &rhs) const;
    IOperand *operator/(const IOperand &rhs) const;
    IOperand *operator%(const IOperand &rhs) const;
    bool operator==(const IOperand &rhs) const;

private:
    void checkNumber(char itr);


protected:
    eOperandType _type;
    int _precision;
    std::string _value;

};

#endif /* !AOPERAND_H_ */

/*
** Int16.h for Operand in /Storage/Epitech/AbstractVM/Operand
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Feb 15 14:34:41 2013 maxime ginters
** Last update Tue Feb 19 14:54:51 2013 maxime ginters
*/

#ifndef INT16_H_
# define INT16_H_

#include "AOperand.h"

class Int16 : public AOperand
{
public:
    Int16(std::string const& value);
    virtual ~Int16() {}
};

#endif /* !INT16_H_ */

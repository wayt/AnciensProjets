/*
** Int32.h for Operand in /Storage/Epitech/AbstractVM/Operand
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Feb 15 14:34:41 2013 maxime ginters
** Last update Tue Feb 19 15:37:57 2013 maxime ginters
*/

#ifndef INT32_H_
# define INT32_H_

#include "AOperand.h"

class Int32 : public AOperand
{
public:
    Int32(std::string const& value);
    virtual ~Int32() {}
};

#endif /* !INT32_H_ */

/*
** TablePePeNoel.h for piscine_cpp_rush2-2016-leroy_v in /home/fest/Epitech/Piscine_tek2/piscine_cpp_rush2-2016-leroy_v
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 21:29:35 2013 maxime ginters
** Last update Sun Jan 20 05:32:03 2013 maxime ginters
*/

#ifndef TABLEPEPENOEL_H_
# define TABLEPEPENOEL_H_

#include "Message.h"
#include "ITable.h"

class TablePePeNoel : public ITable
{
public:
    explicit TablePePeNoel();
    virtual ~TablePePeNoel();
    Object* take(unsigned int mask);
    void put(Object* obj);
    std::string* Look();
    bool isBroken() const;
    TablePePeNoel& operator<<(Object* obj);

private:
    size_t _getObjCount() const;
    Object* _objects[10];
    bool _broken;
};

#endif /* !TABLEPEPENOEL_H_ */
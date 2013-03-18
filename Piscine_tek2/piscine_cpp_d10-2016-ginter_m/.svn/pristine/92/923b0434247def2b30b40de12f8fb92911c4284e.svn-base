/*
** Squad.hh for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 16:15:01 2013 maxime ginters
** Last update Fri Jan 18 17:32:36 2013 maxime ginters
*/

#ifndef SQUAD_H_
# define SQUAD_H_

#include <vector>
#include "ISquad.hh"
#include "ISpaceMarine.hh"

class Squad : public ISquad
{
public:
    explicit Squad();
    virtual ~Squad();

    int getCount() const;
    ISpaceMarine* getUnit(int index);
    int push(ISpaceMarine* unit);
private:
    std::vector<ISpaceMarine*> _vector;
};

#endif /* !SQUAD_H_ */

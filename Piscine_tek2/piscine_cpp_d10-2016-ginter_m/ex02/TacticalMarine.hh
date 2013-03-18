/*
** TacticalMarine.hh for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 16:56:54 2013 maxime ginters
** Last update Fri Jan 18 17:14:44 2013 maxime ginters
*/

#ifndef TACTICALMARINE_H_
# define TACTICALMARINE_H_

#include "ISpaceMarine.hh"

class TacticalMarine : public ISpaceMarine
{
public:
    explicit TacticalMarine();
    virtual ~TacticalMarine();

    ISpaceMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif /* !TACTICALMARINE_H_ */

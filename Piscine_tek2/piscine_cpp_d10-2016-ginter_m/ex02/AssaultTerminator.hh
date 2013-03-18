/*
** AssaultTerminator.hh for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 17:15:50 2013 maxime ginters
** Last update Fri Jan 18 17:21:46 2013 maxime ginters
*/

#ifndef ASSAULTTERMINATOR_H_
# define ASSAULTTERMINATOR_H_

#include "ISpaceMarine.hh"

class AssaultTerminator : public ISpaceMarine
{
public:
    explicit AssaultTerminator();
    virtual ~AssaultTerminator();

    ISpaceMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};



#endif /* !ASSAULTTERMINATOR_H_ */

/*
** Hunter.hh for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d09-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 17 18:20:53 2013 maxime ginters
** Last update Thu Jan 17 18:32:40 2013 maxime ginters
*/

#ifndef HUNTER_H_
# define HUNTER_H_

#include <string>
#include "Character.hh"
#include "Warrior.hh"

class Hunter : public virtual Character, private Warrior
{
public:
    explicit Hunter(std::string const& name, int level);
    virtual ~Hunter() {}
    int CloseAttack();
    int RangeAttack();
    void Heal();
    void RestorePower();
private:
    std::string const _weapon;
};

#endif /* !HUNTER_H_ */

/*
** Character.hh for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 14:14:40 2013 maxime ginters
** Last update Fri Jan 18 14:57:33 2013 maxime ginters
*/

#ifndef CHARACTER_H_
# define CHARACTER_H_

#include <string>
#include "AWeapon.hh"
#include "AEnemy.hh"

class Character
{
public:
    explicit Character(std::string const& name);
    virtual ~Character() {}

    int getAP() const;
    void recoverAP();
    void equip(AWeapon* weapon);
    void attack(AEnemy* target);
    std::string const& getName() const;
    AWeapon const* getWeapon() const;
private:
    AWeapon* _weapon;
    int _ap;
    std::string const _name;
};

std::ostream& operator<<(std::ostream& stream, Character const& me);

#endif /* !CHARACTER_H_ */

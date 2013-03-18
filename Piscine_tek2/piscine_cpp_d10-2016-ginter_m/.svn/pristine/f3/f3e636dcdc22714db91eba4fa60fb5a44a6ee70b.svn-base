/*
** AWeapon.hh for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 10:58:19 2013 maxime ginters
** Last update Fri Jan 18 15:07:16 2013 maxime ginters
*/

#ifndef AWEAPON_H_
# define AWEAPON_H_

#include <string>

class AWeapon
{
public:
    explicit AWeapon(std::string const& name, int apcost, int damage);
    virtual ~AWeapon() {}

    std::string const& getName() const;
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;
protected:
    int const _apcost;
    int _damage;
    std::string const _name;

};

#endif /* !AWEAPON_H_ */

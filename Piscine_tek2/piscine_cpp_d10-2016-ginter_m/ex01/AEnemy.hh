/*
** AEnemy.hh for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 13:48:31 2013 maxime ginters
** Last update Fri Jan 18 14:54:05 2013 maxime ginters
*/

#ifndef AENEMY_H_
# define AENEMY_H_

#include <string>

class AEnemy
{
public:
    explicit AEnemy(int hp, std::string const& type);
    virtual ~AEnemy() {}
    std::string const& getType() const;
    int getHP() const;

    virtual void takeDamage(int damage);
protected:
    int _hp;
    std::string const _type;
};

#endif /* !AENEMY_H_ */

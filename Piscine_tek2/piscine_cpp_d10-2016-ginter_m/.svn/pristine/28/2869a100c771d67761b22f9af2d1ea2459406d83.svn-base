/*
** Character.hh for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 00:53:51 2013 maxime ginters
** Last update Sat Jan 19 01:09:00 2013 maxime ginters
*/

#ifndef CHARACTER_H_
# define CHARACTER_H_

#include <string>
#include "ICharacter.hh"

class Character : public ICharacter
{
public:
    explicit Character(std::string const& name);
    explicit Character(Character const& other);
    virtual ~Character();
    Character& operator=(Character const& other);

    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
private:
    std::string _name;
    AMateria* _inventory[4];
};

#endif /* !CHARACTER_H_ */

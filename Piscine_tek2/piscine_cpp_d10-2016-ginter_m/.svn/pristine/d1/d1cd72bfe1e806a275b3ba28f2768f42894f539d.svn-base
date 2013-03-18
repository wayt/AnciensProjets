/*
** AMateria.hh for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 00:17:24 2013 maxime ginters
** Last update Sat Jan 19 01:51:31 2013 maxime ginters
*/

#ifndef AMATERIA_H_
# define AMATERIA_H_

#include <string>

class ICharacter;

class AMateria
{
public:
    explicit AMateria(std::string const& type);
    virtual ~AMateria();

    std::string const& getType() const;
    unsigned int getXP() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
private:
    unsigned int xp_;
    std::string type_;
};

#endif /* !AMATERIA_H_ */

/*
** Ratatouille.h for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 18:40:51 2013 maxime ginters
** Last update Thu Jan 24 18:53:54 2013 maxime ginters
*/

#ifndef RATATOUILLE_H_
# define RATATOUILLE_H_

#include <string>
#include <sstream>

class Ratatouille
{
public:
    Ratatouille();
    Ratatouille(Ratatouille const& other);
    virtual ~Ratatouille();
    Ratatouille& operator=(Ratatouille const& other);

    Ratatouille& addVegetable(unsigned char c);
    Ratatouille& addCondiment(unsigned int i);
    Ratatouille& addSpice(double d);
    Ratatouille& addSauce(std::string const& s);

    std::string kooc();
private:
    std::ostringstream _ss;
};

#endif /* !RATATOUILLE_H_ */

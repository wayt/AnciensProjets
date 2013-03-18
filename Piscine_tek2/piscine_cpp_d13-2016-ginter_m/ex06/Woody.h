/*
** Woody.h for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d13-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 21 11:25:03 2013 maxime ginters
** Last update Mon Jan 21 17:06:50 2013 maxime ginters
*/

#ifndef WOODY_H_
# define WOODY_H_

#include <string>
#include "Toy.h"

class Woody : public Toy
{
public:
    explicit Woody(std::string const& name, std::string const& filename = "woody.txt");
    virtual ~Woody();

    bool speak(std::string const& speech);
};

#endif /* !WOODY_H_ */

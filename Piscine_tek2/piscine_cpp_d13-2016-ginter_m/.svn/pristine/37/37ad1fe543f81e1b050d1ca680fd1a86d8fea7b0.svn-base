/*
** Toy.h for ex00 in /home/fest/Epitech/Piscine_tek2/jour13/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 21 10:29:01 2013 maxime ginters
** Last update Mon Jan 21 14:23:09 2013 maxime ginters
*/

#ifndef TOY_H_
# define TOY_H_

#include <iostream>
#include <string>
#include "Picture.h"

class Toy
{
public:
    enum ToyType
    {
        BASIC_TOY   = 0,
        ALIEN       = 1,
        BUZZ        = 2,
        WOODY       = 3
    };

    Toy();
    Toy(Toy const& other);
    Toy(ToyType type, std::string const& name, std::string const& filename);
    Toy& operator=(Toy const& other);

    ToyType getType() const;
    std::string const& getName() const;
    void setName(std::string const& name);
    bool setAscii(std::string const& filename);
    std::string const& getAscii() const;

    virtual void speak(std::string const& speech);

    Toy& operator<<(std::string const& file);
protected:
    ToyType _type;
    std::string _name;
    Picture _picture;
};

std::ostream& operator<<(std::ostream& stream, Toy const& toy);

#endif /* !TOY_H_ */

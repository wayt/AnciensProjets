/*
** Toy.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/jour13/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 21 10:34:13 2013 maxime ginters
** Last update Mon Jan 21 17:06:44 2013 maxime ginters
*/

#include "Toy.h"

Toy::Toy() :
    _type(BASIC_TOY), _name("toy"), _picture(""), _error()
{}

Toy::Toy(Toy const& other) :
    _type(other.getType()), _name(other.getName()), _picture(other._picture), _error()
{}

Toy::Toy(ToyType type, std::string const& name, std::string const& filename) :
    _type(type), _name(name), _picture(filename), _error()
{}

Toy& Toy::operator=(Toy const& other)
{
    _type = other.getType();
    _name = other.getName();
    _picture = other._picture;
    return *this;
}

Toy::ToyType Toy::getType() const
{
    return _type;
}

std::string const& Toy::getName() const
{
    return _name;
}

void Toy::setName(std::string const& name)
{
    _name = name;
}

bool Toy::setAscii(std::string const& filename)
{
    _error.clear();
    if (!_picture.getPictureFromFile(filename))
    {
        _error.record(Error::PICTURE, "bad new illustration", "setAscii");
        return false;
    }
    return true;

}

std::string const& Toy::getAscii() const
{
    return _picture.data;
}

bool Toy::speak(std::string const& speech)
{
    std::cout << getName() << " \"" << speech << "\"" << std::endl;
    return true;
}

std::ostream& operator<<(std::ostream& stream, Toy const& toy)
{
    stream << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return stream;
}

Toy::Error& Toy::getLastError()
{
    return _error;
}

Toy& Toy::operator<<(std::string const& file)
{
    _picture.data = file;
    return *this;
}

bool Toy::speak_es(std::string const& file)
{
    (void)file;
    _error.record(Error::SPEAK, "wrong mode", "speak_es");
    return false;
}

Toy::Error::Error() :
    type(UNKNOWN), _what(""), _where("")
{}

std::string const& Toy::Error::what() const
{
    return _what;
}

std::string const& Toy::Error::where() const
{
    return _where;
}

void Toy::Error::clear()
{
    record(UNKNOWN, "", "");
}

void Toy::Error::record(Toy::Error::ErrorType ty, std::string const& what, std::string const& where)
{
    type = ty;
    _what = what;
    _where = where;
}

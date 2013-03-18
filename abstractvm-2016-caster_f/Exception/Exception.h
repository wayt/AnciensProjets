/*
** Exception.h for Exception in /Storage/Epitech/AbstractVM/Exception
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Feb 15 14:25:25 2013 maxime ginters
** Last update Fri Feb 22 13:38:24 2013 maxime ginters
*/

#ifndef EXCEPTION_H_
# define EXCEPTION_H_

#include <exception>
#include <sstream>

namespace Exception
{

class ExceptOverflow : public std::exception
{
public:
    ExceptOverflow() {}
    const char* what() const throw()
    {
        return "Overflow";
    }
};

class ExceptUnderflow : public std::exception
{
public:
    ExceptUnderflow() {}
    const char* what() const throw()
    {
        return "Underflow";
    }
};

class ExceptZero : public std::exception
{
public:
    ExceptZero() {}
    const char* what() const throw()
    {
        return "Division or Modulo by zero";
    }
};

class ExceptDecimaleModulo : public std::exception
{
public:
    ExceptDecimaleModulo() {}
    const char* what() const throw()
    {
        return "Modulo on decimale value";
    }
};

class ExceptStack : public std::exception
{
private:
    int _line;
public:
    ExceptStack(int line) : _line(line) {}
    const char* what() const throw()
    {
        std::stringstream ss;
        ss << "Line " << _line << " : Not enought element";
        return ss.str().c_str();
    }
};

class ExceptNotInt8 : public std::exception
{
private:
    int _line;
public:
    ExceptNotInt8(int line) : _line(line) {}
    const char* what() const throw()
    {
        std::stringstream ss;
        ss << "Line " << _line << " : Is not an Int8";
        return ss.str().c_str();
    }
};

class ExceptNoExit : public std::exception
{
public:
    ExceptNoExit() {}
    const char* what() const throw()
    {
        return "The program need : exit";
    }
};

class ExceptAssert : public std::exception
{
private:
    int _line;
public:
    ExceptAssert(int line) : _line(line) {}
    const char* what() const throw()
    {
        std::stringstream ss;
        ss << "Line " << _line << " : Bad assert";
        return ss.str().c_str();
    }
};

class ExceptTypeNotFound : public std::exception
{
public:
    ExceptTypeNotFound() {}
    const char* what() const throw()
    {
        return "Type doesn't exists";
    }
};

class ExceptCommandNotFound : public std::exception
{
private:
    int _line;
public:
    ExceptCommandNotFound(int line) : _line(line)
    {
    }
    const char* what() const throw()
    {
        std::stringstream ss;
        ss << "Line " << _line << " : Command doesn't exists";
        return ss.str().c_str();
    }
};

class ExceptFileNotFound : public std::exception
{
public:
    ExceptFileNotFound() {}
    const char* what() const throw()
    {
        return "File doesn't exists";
    }
};

class ExceptInvalideNumber : public std::exception
{
public:
    ExceptInvalideNumber() {}
    const char* what() const throw()
    {
        return "Invalide number";
    }
};

}
#endif /* !EXCEPTION_H_ */

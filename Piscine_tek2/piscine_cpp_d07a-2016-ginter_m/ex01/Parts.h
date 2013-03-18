/*
** Parts.h for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07a-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 21:40:42 2013 maxime ginters
** Last update Tue Jan 15 21:56:42 2013 maxime ginters
*/

#ifndef PARTS_H_
# define PARTS_H_

#include <string>

class Arms
{
public:
    explicit Arms(std::string const& serial = "A-01", bool functionnal = true);
    virtual ~Arms() {}

    bool isFunctionnal() const;
    std::string const& serial() const;
    void informations() const;
private:
    std::string _serial;
    bool _functionnal;
};

class Legs
{
public:
    explicit Legs(std::string const& serial = "L-01", bool functionnal = true);
    virtual ~Legs() {}

    bool isFunctionnal() const;
    std::string const& serial() const;
    void informations() const;
private:
    std::string _serial;
    bool _functionnal;
};

class Head
{
public:
    explicit Head(std::string const& serial = "H-01", bool functionnal = true);
    virtual ~Head() {}

    bool isFunctionnal() const;
    std::string const& serial() const;
    void informations() const;
private:
    std::string _serial;
    bool _functionnal;
};

#endif /* !PARTS_H_ */

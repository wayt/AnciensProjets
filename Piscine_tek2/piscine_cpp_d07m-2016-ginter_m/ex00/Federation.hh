/*
** Federation.hh for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 09:37:54 2013 maxime ginters
** Last update Tue Jan 15 10:37:27 2013 maxime ginters
*/

#ifndef FEDERATION_H_
# define FEDERATION_H_

#include <string>
#include "Warpsystem.hh"

namespace Federation
{
namespace Starfleet
{

class Ship
{
public:
    explicit Ship(int length, int width, std::string name, short maxWarp);
    virtual ~Ship() {}

    void setupCore(WarpSystem::Core* core);
    void checkCore();
private:
    int _length;
    int _width;
    std::string _name;
    short _maxWarp;
    WarpSystem::Core* _core;
};

}

class Ship
{
public:
    explicit Ship(int length, int width, std::string name, short maxWarp = 1);
    virtual ~Ship() {}

    void setupCore(WarpSystem::Core* core);
    void checkCore();
private:
    int _length;
    int _width;
    std::string _name;
    short _maxWarp;
    WarpSystem::Core* _core;
};

}

#endif /* !FEDERATION_H_ */

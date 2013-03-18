/*
** Federation.hh for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 09:37:54 2013 maxime ginters
** Last update Tue Jan 15 14:47:29 2013 maxime ginters
*/

#ifndef FEDERATION_H_
# define FEDERATION_H_

#include <string>
#include "Warpsystem.hh"
#include "Destination.hh"
#include "Borg.hh"

namespace Borg
{
    class Ship;
}

namespace Federation
{
namespace Starfleet
{

class Captain;

class Ship
{
public:
    Ship();
    Ship(int length, int width, std::string name, short maxWarp, int torpedo);

    virtual ~Ship() {}

    void setupCore(WarpSystem::Core* core);
    void checkCore();
    void promote(Captain* cap);

    bool move(int warp, Destination d);
    bool move(int warp);
    bool move(Destination d);
    bool move();

    int getShield();
    void setShield(int val);
    int getTorpedo();
    void setTorpedo(int val);
    void fire(Borg::Ship* target);
    void fire(int torpedoes, Borg::Ship* target);
private:
    int _length;
    int _width;
    std::string _name;
    short _maxWarp;
    WarpSystem::Core* _core;
    Captain* _captain;
    Destination _home;
    Destination _location;
    int _shield;
    int _photonTorpedo;
};

class Captain
{
public:
    explicit Captain(std::string name);
    virtual ~Captain() {}

    std::string getName();
    int getAge();
    void setAge(int age);
private:
    std::string _name;
    int _age;
};

class Ensign
{
public:
    explicit Ensign(std::string name);
    virtual ~Ensign() {}
private:
    std::string _name;
};

} // !namespace Starfleet

class Ship
{
public:
    explicit Ship(int length, int width, std::string name, short maxWarp = 1);
    virtual ~Ship() {}

    void setupCore(WarpSystem::Core* core);
    void checkCore();

    bool move(int warp, Destination d);
    bool move(int warp);
    bool move(Destination d);
    bool move();

    WarpSystem::Core* getCore();
private:
    int _length;
    int _width;
    std::string _name;
    short _maxWarp;
    WarpSystem::Core* _core;
    Destination _home;
    Destination _location;
};

} // !namespace Federation

#endif /* !FEDERATION_H_ */

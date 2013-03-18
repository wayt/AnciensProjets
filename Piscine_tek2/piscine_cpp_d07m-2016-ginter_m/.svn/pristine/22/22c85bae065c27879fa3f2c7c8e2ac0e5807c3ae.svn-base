/*
** Borg.hh for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 11:06:53 2013 maxime ginters
** Last update Tue Jan 15 14:47:57 2013 maxime ginters
*/

#ifndef BORG_H_
# define BORG_H_

#include "Warpsystem.hh"
#include "Federation.hh"
#include "Destination.hh"

namespace Federation
{
    namespace Starfleet
    {
        class Ship;
    }
    class Ship;
}
namespace Borg
{

class Ship
{
public:
    explicit Ship(int wF, short repair = 3);
    virtual ~Ship() {}

    void setupCore(WarpSystem::Core* core);
    void checkCore();

    bool move(int warp, Destination d);
    bool move(int warp);
    bool move(Destination d);
    bool move();

    int getShield();
    void setShield(int val);
    int getWeaponFrequency();
    void setWeaponFrequency(int val);
    short getRepair();
    void setRepair(short val);
    void fire(Federation::Starfleet::Ship* target);
    void fire(Federation::Ship* target);
    void repair();
private:
    int _side;
    short _maxWarp;
    WarpSystem::Core* _core;
    Destination _home;
    Destination _location;
    int _shield;
    int _weaponFrequency;
    short _repair;
};

} // !namespace Borg

#endif /* !BORG_H_ */

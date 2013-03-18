/*
** Borg.hh for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 11:06:53 2013 maxime ginters
** Last update Tue Jan 15 11:17:37 2013 maxime ginters
*/

#ifndef BORG_H_
# define BORG_H_

#include "Warpsystem.hh"

namespace Borg
{

class Ship
{
public:
    explicit Ship();
    virtual ~Ship() {}

    void setupCore(WarpSystem::Core* core);
    void checkCore();
private:
    int _side;
    short _maxWarp;
    WarpSystem::Core* _core;
};

} // !namespace Borg

#endif /* !BORG_H_ */

/*
** ScopLock.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 21 13:07:48 2013 maxime ginters
** Last update Sun Apr 21 13:09:55 2013 maxime ginters
*/

#include "ScopLock.h"

ScopLock::ScopLock(Mutex& mutex) : _mutex(mutex)
{
    _mutex.lock();
}

ScopLock::~ScopLock()
{
    _mutex.unlock();
}


/*
** ScopLock.h for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Apr 21 13:08:24 2013 maxime ginters
** Last update Sun Apr 21 13:09:57 2013 maxime ginters
*/

#ifndef SCOPLOCK_H_
# define SCOPLOCK_H_

#include "Mutex.h"

class ScopLock
{
public:
    ScopLock(Mutex& mutex);
    virtual ~ScopLock();
private:
    Mutex& _mutex;
};

#endif /* !SCOPLOCK_H_ */

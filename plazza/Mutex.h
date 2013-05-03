/*
** Mutex.h for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 11:52:10 2013 maxime ginters
** Last update Tue Apr 16 15:42:58 2013 maxime ginters
*/

#ifndef MUTEX_H_
# define MUTEX_H_

#include <pthread.h>
#include "SharedDefines.h"

class Mutex
{
public:
    Mutex();
    ~Mutex();

    int32 lock();
    int32 unlock();

    pthread_mutex_t& getMutex();

private:
    pthread_mutex_t _mutex;
};

#endif /* !MUTEX_H_ */

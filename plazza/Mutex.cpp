/*
** Mutex.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 11:52:10 2013 maxime ginters
** Last update Tue Apr 16 12:43:42 2013 maxime ginters
*/

#include "Mutex.h"

Mutex::Mutex()
{
    pthread_mutex_init(&_mutex, NULL);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&_mutex);
}

int32 Mutex::lock()
{
    return pthread_mutex_lock(&_mutex);
}

int32 Mutex::unlock()
{
    return pthread_mutex_unlock(&_mutex);
}

pthread_mutex_t& Mutex::getMutex()
{
    return _mutex;
}

/*
** Runnable.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 11:27:52 2013 maxime ginters
** Last update Tue Apr 16 11:51:17 2013 maxime ginters
*/

#include "Runnable.h"

static void* runnable(void* data)
{
    (*((Runnable*)data))();
    return NULL;
}

void Runnable::run()
{
    _stop = false;
    pthread_create(&_thread, NULL, runnable, this);
}

void Runnable::stop()
{
    _stop = true;
}

bool Runnable::isStopped() const
{
    return _stop;
}


int Runnable::join()
{
    return pthread_join(_thread, NULL);
}


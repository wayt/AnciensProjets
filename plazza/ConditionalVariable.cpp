/*
** ConditionalVariable.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 19:33:52 2013 maxime ginters
** Last update Fri Apr 19 13:16:35 2013 maxime ginters
*/

#include <iostream>
#include <cstring>
#include <errno.h>
#include "ConditionalVariable.h"

ConditionalVariable::ConditionalVariable()
{
    pthread_condattr_init(&_cond_attr);
    pthread_cond_init(&_cond, &_cond_attr);
}

ConditionalVariable::~ConditionalVariable()
{
    pthread_cond_destroy(&_cond);
}

void ConditionalVariable::notify()
{
    pthread_cond_broadcast(&_cond);
}

void ConditionalVariable::wait(Mutex& mutex)
{
    pthread_cond_wait(&_cond, &mutex.getMutex());
}

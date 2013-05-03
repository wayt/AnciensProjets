/*
** ConditionalVariable.h for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 19:31:42 2013 maxime ginters
** Last update Fri Apr 19 12:14:40 2013 maxime ginters
*/

#ifndef CONDITIONALVARIABLE_H_
# define CONDITIONALVARIABLE_H_

#include <pthread.h>
#include "Mutex.h"

class ConditionalVariable
{
public:
    ConditionalVariable();
    ~ConditionalVariable();
    void notify();
    void wait(Mutex& mutex);

private:
    pthread_cond_t _cond;
    pthread_condattr_t _cond_attr;
};

#endif /* !CONDITIONALVARIABLE_H_ */

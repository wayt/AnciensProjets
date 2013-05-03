/*
** Runnable.h for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 11:27:52 2013 maxime ginters
** Last update Tue Apr 16 11:49:41 2013 maxime ginters
*/

#ifndef RUNNABLE_H_
# define RUNNABLE_H_

#include <pthread.h>

class Runnable
{
public:
    void run();
    void stop();
    bool isStopped() const;
    int join();
    virtual void operator()() = 0;

private:
    pthread_t _thread;
    bool _stop;
};

#endif /* !RUNNABLE_H_ */

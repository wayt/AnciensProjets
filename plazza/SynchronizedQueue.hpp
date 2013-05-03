/*
** SynchronizedQueue.h for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 12:38:06 2013 maxime ginters
** Last update Sun Apr 21 13:12:15 2013 maxime ginters
*/

#ifndef SYNCHRONIZEDQUEUE_H_
# define SYNCHRONIZEDQUEUE_H_

#include <queue>
#include <pthread.h>
#include "ConditionalVariable.h"
#include "Mutex.h"
#include "ScopLock.h"

template<class T>
class SynchronizedQueue
{
public:
    void add(T* data)
    {
        ScopLock lock(_mutex);

        _queue.push(data);
        _cond.notify();
    }

    T* get()
    {
        ScopLock lock(_mutex);
        while (!_queue.size())
            _cond.wait(_mutex);

        T* data = _queue.front();
        _queue.pop();
        return data;
    }

    uint32 size()
    {
        ScopLock lock(_mutex);
        return _queue.size();
    }

private:
    Mutex _mutex;
    std::queue<T*> _queue;
    ConditionalVariable _cond;
};

#endif /* !SYNCHRONIZEDQUEUE_H_ */

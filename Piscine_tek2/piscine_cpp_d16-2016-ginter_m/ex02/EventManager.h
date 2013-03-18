/*
** EventManager.h for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 15:38:32 2013 maxime ginters
** Last update Thu Jan 24 16:27:45 2013 maxime ginters
*/

#ifndef EVENTMANAGER_H_
# define EVENTMANAGER_H_

#include <iostream>
#include <string>
#include <list>
#include "Event.h"

class EventManager
{
public:
    EventManager();
    virtual ~EventManager();
    EventManager(EventManager const& other);
    EventManager& operator=(EventManager const& other);

    void addEvent(Event const& event);
    void removeEventsAt(unsigned int time);
    void dumpEvents() const;
    void dumpEventAt(unsigned int time) const;
    void addTime(unsigned int time);
    void addEventList(std::list<Event>& list);

    static bool _listSort(Event const& e1, Event const& e2);
private:
    std::list<Event> _list;
    unsigned int _time;
};

#endif /* !EVENTMANAGER_H_ */

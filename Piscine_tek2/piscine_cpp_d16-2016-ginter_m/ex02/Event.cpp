/*
** Event.cpp for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 15:14:09 2013 maxime ginters
** Last update Thu Jan 24 16:12:18 2013 maxime ginters
*/

#include "Event.h"

Event::Event() :
    _time(0), _event("")
{}

Event::Event(unsigned int time, std::string const& event) :
    _time(time), _event(event)
{}

Event::~Event()
{}

Event::Event(Event const& other) :
    _time(other._time), _event(other._event)
{}

Event& Event::operator=(Event const& other)
{
    _time = other._time;
    _event = other._event;
    return *this;
}

unsigned int Event::getTime() const
{
    return _time;
}

std::string const& Event::getEvent() const
{
    return _event;
}

void Event::setTime(unsigned int time)
{
    _time = time;
}

void Event::setEvent(std::string const& event)
{
    _event = event;
}

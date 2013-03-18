/*
** Event.h for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 15:07:20 2013 maxime ginters
** Last update Thu Jan 24 16:12:54 2013 maxime ginters
*/

#ifndef EVENT_H_
# define EVENT_H_

#include <string>

class Event
{
public:
    Event();
    Event(unsigned int time, std::string const& event);
    virtual ~Event();
    Event(Event const& other);
    Event& operator=(Event const& other);

    unsigned int getTime() const;
    std::string const& getEvent() const;
    void setTime(unsigned int time);
    void setEvent(std::string const& event);
private:
    unsigned int _time;
    std::string _event;
};

#endif /* !EVENT_H_ */

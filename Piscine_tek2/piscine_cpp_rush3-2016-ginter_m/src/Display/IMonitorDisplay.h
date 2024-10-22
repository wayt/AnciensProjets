/*
** IMonitorDisplay.h for src in /home/leroy_v/github/MyGKrellM/src
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Tue Jan 29 00:34:01 2013 vincent leroy
** Last update Wed Jan 30 11:01:35 2013 maxime ginters
*/

#ifndef IMONITORDISPLAY_H_
# define IMONITORDISPLAY_H_

#include <curses.h>
#ifdef scroll
#undef scroll
#endif
#include <iostream>
#include <string>
#include <QWidget>
#include <QGridLayout>

class IMonitorDisplay
{
public:
    virtual ~IMonitorDisplay() {}

    virtual void addValue(std::string const&) = 0;
    virtual void display() = 0;
    virtual void init(WINDOW*, int, int) = 0;
    virtual QWidget* init(QWidget*) = 0;
    virtual void setMax(std::string const&) = 0;
    virtual std::string const& getUnite() const = 0;
    virtual void setUnite(std::string const&) = 0;
};

#endif /* !IMONITORDISPLAY_H_ */

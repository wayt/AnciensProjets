/*
** AModuleCore.h for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 00:21:19 2013 fabien casters
** Last update Wed Jan 30 01:39:57 2013 vincent leroy
*/

#ifndef AMODULECORE_H_
# define AMODULECORE_H_

#include <list>
#include "IMonitorModule.h"

class AModuleCore
{
public:
    enum DisplayMode
    {
        MODE_QT = 0,
        MODE_NCURSES = 1
    };
    enum DisplayType
    {
        TYPE_TEXT = 0,
        TYPE_GRAPH = 1,
        TYPE_BARRE = 2
    };
    AModuleCore(DisplayMode mode = MODE_NCURSES);
    virtual ~AModuleCore();

    void addModule(IMonitorModule*);
    DisplayMode getMode() const;
    void setMode(DisplayMode);

    bool isRunning() const;
    void setRunning(bool);

    void refresh();
    virtual void display() = 0;
    virtual void init() = 0;

protected:
    std::list<IMonitorModule*> _modules;
    DisplayMode _mode;
    bool _running;
};

#endif


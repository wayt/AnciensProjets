/*
** AModuleCore.cpp for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 00:38:51 2013 fabien casters
** Last update Wed Jan 30 01:39:46 2013 vincent leroy
*/

#include "AModuleCore.h"

AModuleCore::AModuleCore(DisplayMode mode)
    : _modules(), _mode(mode), _running(true)
{
}

AModuleCore::~AModuleCore()
{
    while (!_modules.empty())
    {
        delete _modules.front();
        _modules.pop_front();
    }
}

void AModuleCore::addModule(IMonitorModule* module)
{
    _modules.push_back(module);
}

AModuleCore::DisplayMode AModuleCore::getMode() const
{
    return _mode;
}

void AModuleCore::refresh()
{
    for (std::list<IMonitorModule*>::iterator it = _modules.begin();
         it != _modules.end(); (*it)->refresh(), ++it);
}

bool AModuleCore::isRunning() const
{
    return _running;
}

void AModuleCore::setRunning(bool running)
{
    _running = running;
}

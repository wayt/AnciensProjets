/*
** AMonitorModule.cpp for src in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 01:05:06 2013 maxime ginters
** Last update Wed Jan 30 01:30:10 2013 maxime ginters
*/

#include <iostream>
#include <map>
#include "AModuleCore.h"
#include "AMonitorModule.h"
#include "DisplayFactory.hpp"

AMonitorModule::AMonitorModule(std::string const& filename, std::string const& name, AModuleCore::DisplayMode mode, AModuleCore::DisplayType type) :
    _stream(), _name(name), _display(NULL)
{
    _stream.open(filename.c_str(), std::ios::in);
    _display = sDisplayFactory->createDisplay(mode, type);
}

AMonitorModule::~AMonitorModule()
{
    if (_stream.is_open())
        _stream.close();
}

std::string const& AMonitorModule::getName() const
{
    return _name;
}

void AMonitorModule::display()
{
    if (!_display)
        return;
    _display->display();
}

IMonitorDisplay* AMonitorModule::getDisplay()
{
    return _display;
}

std::string const& AMonitorModule::getUnite() const
{
    return _display->getUnite();
}

void AMonitorModule::setUnite(std::string const& unite)
{
    if (!_display)
        return;
    _display->setUnite(unite);
}

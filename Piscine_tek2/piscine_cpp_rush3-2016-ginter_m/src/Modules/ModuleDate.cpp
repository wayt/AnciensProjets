/*
** ModuleDate.cpp for Modules in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src/Modules
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 19:56:32 2013 maxime ginters
** Last update Tue Jan 29 20:03:44 2013 maxime ginters
*/

#include <ctime>
#include <string>
#include "ModuleDate.h"

ModuleDate::ModuleDate(AModuleCore::DisplayMode mode, AModuleCore::DisplayType type) :
    AMonitorModule("/dev/null", "Date", mode, type)
{}

ModuleDate::~ModuleDate()
{}

void ModuleDate::refresh()
{
    if (!_display)
        return;
    time_t t;
    time(&t);
    std::string tm = ctime(&t);

    tm[tm.length() - 1] = 0;
    _display->addValue(tm);
    _display->setMax("");
}

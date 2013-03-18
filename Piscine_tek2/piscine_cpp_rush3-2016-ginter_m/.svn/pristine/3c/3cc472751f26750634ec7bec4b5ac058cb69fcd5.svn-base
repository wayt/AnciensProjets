/*
** ModuleKernelVersion.cpp for Modules in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src/Modules
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 16:26:03 2013 maxime ginters
** Last update Tue Jan 29 16:49:33 2013 maxime ginters
*/

#include <iostream>
#include <sstream>
#include <sys/utsname.h>
#include "ModuleKernelVersion.h"

ModuleKernelVersion::ModuleKernelVersion(AModuleCore::DisplayMode mode, AModuleCore::DisplayType type) :
    AMonitorModule("/proc/version", "Version", mode, type)
{}

ModuleKernelVersion::~ModuleKernelVersion()
{}

void ModuleKernelVersion::refresh()
{
    if (!_display)
        return;
    struct utsname unameData;
    if (uname(&unameData) == -1)
        return;

    std::stringstream ss;
    ss << unameData.sysname;
    ss << " Version ";
    ss << unameData.release;
    ss << ", ";
    ss << unameData.version;

    _display->addValue(ss.str());
    _display->setMax("");
}

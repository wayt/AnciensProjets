/*
** ModuleMachineName.cpp for Modules in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src/Modules
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 15:16:56 2013 maxime ginters
** Last update Tue Jan 29 15:46:31 2013 maxime ginters
*/

#include <unistd.h>
#include <sstream>
#include "ModuleMachineName.h"

ModuleMachineName::ModuleMachineName(AModuleCore::DisplayMode mode, AModuleCore::DisplayType type) :
    AMonitorModule("/proc/sys/kernel/hostname", "Machine", mode, type)
{}

ModuleMachineName::~ModuleMachineName()
{}

void ModuleMachineName::refresh()
{
    if (!_stream.is_open() || !_display)
        return;
    _stream.clear();
    _stream.seekg(0, std::ios::beg);
    std::string hostname = "";
    if (_stream.good())
        std::getline(_stream, hostname);

    if (hostname.empty())
        return;
    std::stringstream ss;
    ss << getlogin();
    ss << "@";
    ss << hostname;

    _display->addValue(ss.str());
    _display->setMax("");
}

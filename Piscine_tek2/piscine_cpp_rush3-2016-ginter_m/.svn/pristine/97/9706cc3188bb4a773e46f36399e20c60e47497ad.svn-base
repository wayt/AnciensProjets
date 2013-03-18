/*
** ModuleRAM.cpp for src in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 03:15:38 2013 maxime ginters
** Last update Wed Jan 30 02:28:03 2013 maxime ginters
*/

#include <sstream>
#include <iostream>
#include <cctype>
#include "AModuleCore.h"
#include "Utils.h"
#include "ModuleRAM.h"

ModuleRAM::ModuleRAM(AModuleCore::DisplayMode mode, AModuleCore::DisplayType type) :
    AMonitorModule("/proc/meminfo", "RAM", mode, type)
{}

ModuleRAM::~ModuleRAM()
{
}

void ModuleRAM::refresh()
{
    if (!_stream.is_open() || !_display)
        return;
    _stream.clear();
    _stream.seekg(0, std::ios::beg);
    std::string value = "";
    std::string max = "";
    std::string cached;
    while (_stream.good())
    {
        std::string line = "";
        std::getline(_stream, line);
        if (line.find("MemTotal") == 0)
            max = _getValue(line);
        else if (line.find("MemFree") == 0)
            value = _getValue(line);
        else if (line.find("Cached") == 0)
            cached = _getValue(line);

    }
    if (value.empty() || max.empty())
        return;
    int val_max = to_int(max.c_str());
    int val = ((val_max - to_int(value.c_str())) - to_int(cached.c_str()));
    setUnite(" KB");
    if (val > 10240)
    {
        val /= 1024;
        val_max /= 1024;
        setUnite(" MB");
    }
    if (val > 10240)
    {
        val /= 1024;
        val_max /= 1024;
        setUnite(" GB");
    }

    std::stringstream ss;
    ss << val;
    _display->addValue(ss.str());
    ss.str("");
    ss << val_max;
    _display->setMax(ss.str());
}

std::string ModuleRAM::_getValue(std::string const& line)
{
    const char* l = line.c_str();
    while (*l)
    {
        if (isdigit(*l))
        {
            std::stringstream ss;
            ss << to_int(l);
            return ss.str();
        }
        ++l;
    }
    return "";
}

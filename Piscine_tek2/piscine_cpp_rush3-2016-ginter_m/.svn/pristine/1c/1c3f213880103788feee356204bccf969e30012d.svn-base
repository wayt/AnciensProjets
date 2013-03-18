#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include "ModuleCPU.h"
#include "AMonitorModule.h"
#include "AModuleCore.h"

ModuleCPU::ModuleCPU(int id, AModuleCore::DisplayMode mode, AModuleCore::DisplayType type) : AMonitorModule("/proc/stat", "CPU", mode, type), _cpuId(id), _lastCheck(0), _lastVal(0)
{
}

ModuleCPU::~ModuleCPU()
{
}

void ModuleCPU::refresh()
{
    if (!_stream.is_open() || !_display)
        return;
    _stream.clear();
    _stream.seekg(0, std::ios::beg);
    std::string value = "";
    std::stringstream ss;
    ss << "cpu";
    if (_cpuId == -1)
        ss << " ";
    else
        ss << _cpuId;
    while (_stream.good())
    {
        std::string line = "";
        std::getline(_stream, line);
        if ((line.find(ss.str())) == 0)
        {
            value = _parseLine(line);
            break;
        }
    }
    setUnite(" \%");
    _display->addValue(value);
    _display->setMax("100");
}

std::string ModuleCPU::_parseLine(std::string const& line)
{
    std::stringstream ss;
    ss << line;
    std::string tmp;
    ss >> tmp;
    int user;
    ss >> user;
    int val = 0;
    if (_lastCheck == 0)
    {
        _lastCheck = time(NULL);
        _lastVal = user;
    }
    else
    {
        time_t tim = time(NULL);
        if (tim - _lastCheck != 0)
           val = (user - _lastVal) / (tim - _lastCheck);
        _lastCheck = tim;
        _lastVal = user;
    }
    ss.str("");
    ss << val;
    return ss.str();
}

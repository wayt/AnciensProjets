#include <string>
#include <sstream>
#include "ModuleNetwork.h"

ModuleNetwork::ModuleNetwork(std::string const& interface, AModuleCore::DisplayMode mode, AModuleCore::DisplayType type) :
    AMonitorModule("/proc/net/dev", "Network", mode, type), _intf(interface), _lastCheck(0), _lastVal(0)
{
}

ModuleNetwork::~ModuleNetwork()
{
}

void ModuleNetwork::refresh()
{
    if (!_stream.is_open() || !_display)
        return;
    _stream.clear();
    _stream.seekg(0, std::ios::beg);
    std::string value = "";
    while (_stream.good())
    {
        std::string line = "";
        std::getline(_stream, line);
        if ((line.find(_intf)) != std::string::npos)
        {
            value = _parseLine(line);
            break;
        }
    }
    _display->addValue(value);
    _display->setMax("");
}

std::string ModuleNetwork::_parseLine(std::string const& line)
{
    std::stringstream ss;
    ss << line;
    std::string tmp;
    ss >> tmp;
    int user;
    ss >> user;
    float val = 0;
    if (_lastCheck == 0)
    {
        _lastCheck = time(NULL);
        _lastVal = user;
    }
    else
    {
        time_t tim = time(NULL);
        if (tim - _lastCheck != 0)
           val = (float)(user - _lastVal) / (tim - _lastCheck);
        _lastCheck = tim;
        _lastVal = user;
    }
    ss.str("");
    setUnite(" b/s");
    if (val > 1024.0f)
    {
        val /= 1024.0f;
        setUnite(" Kb/s");
    }
    if (val > 1024.0f)
    {
        val /= 1024.0f;
        setUnite(" Mb/s");
    }
    ss << val;
    return ss.str();
}

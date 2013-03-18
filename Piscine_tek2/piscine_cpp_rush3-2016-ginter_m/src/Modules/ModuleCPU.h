#ifndef _MODULECPU_H_
#define _MODULECPU_H_

#include <ctime>
#include <string>
#include "AMonitorModule.h"
#include "AModuleCore.h"

class ModuleCPU  : public AMonitorModule
{
public:
    ModuleCPU(int id = 0, AModuleCore::DisplayMode mode = AModuleCore::MODE_NCURSES, AModuleCore::DisplayType type = AModuleCore::TYPE_TEXT);
    ~ModuleCPU();
    void refresh();

private:
    int _cpuId;
    time_t _lastCheck;
    int _lastVal;
    std::string _parseLine(std::string const& line);
};

#endif

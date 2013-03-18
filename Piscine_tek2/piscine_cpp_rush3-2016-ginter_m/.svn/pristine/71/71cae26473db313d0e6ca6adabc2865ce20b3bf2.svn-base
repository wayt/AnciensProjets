#ifndef MODULENETWORK_H_
# define MODULENETWORK_H_

#include <string>
#include "AModuleCore.h"
#include "AMonitorModule.h"

class ModuleNetwork : public AMonitorModule
{
public:
    ModuleNetwork(std::string const&, AModuleCore::DisplayMode mode = AModuleCore::MODE_NCURSES, AModuleCore::DisplayType type = AModuleCore::TYPE_TEXT);
    virtual ~ModuleNetwork();
    void refresh();
private:
    std::string _intf;
    time_t _lastCheck;
    int _lastVal;
    std::string _parseLine(std::string const& line);
};

#endif /* !MODULENETWORK_H_ */

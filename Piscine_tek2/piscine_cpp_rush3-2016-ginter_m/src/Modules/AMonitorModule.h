/*
** AMonitorModule.h for src in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 00:57:28 2013 maxime ginters
** Last update Wed Jan 30 01:27:34 2013 maxime ginters
*/

#ifndef AMONITORMODULE_H_
# define AMONITORMODULE_H_

#include <fstream>
#include "AModuleCore.h"
#include "IMonitorModule.h"

class AMonitorModule : public IMonitorModule
{
public:
    AMonitorModule(std::string const& filename, std::string const& name, AModuleCore::DisplayMode mode = AModuleCore::MODE_NCURSES, AModuleCore::DisplayType type = AModuleCore::TYPE_TEXT);
    virtual ~AMonitorModule();

    std::string const& getName() const;
    void display();
    IMonitorDisplay* getDisplay();
    std::string const& getUnite() const;
    void setUnite(std::string const& unite);

protected:
    std::ifstream _stream;
    std::string const _name;
    IMonitorDisplay* _display;
};

#endif /* !AMONITORMODULE_H_ */

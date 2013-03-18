/*
** ModuleRAM.h for src in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 03:10:06 2013 maxime ginters
** Last update Tue Jan 29 14:50:53 2013 fabien casters
*/

#ifndef MODULERAM_H_
# define MODULERAM_H_

#include "AMonitorModule.h"

class ModuleRAM : public AMonitorModule
{
public:
    ModuleRAM(AModuleCore::DisplayMode mode = AModuleCore::MODE_NCURSES, AModuleCore::DisplayType type = AModuleCore::TYPE_TEXT);
    virtual ~ModuleRAM();

    void refresh();
private:
    std::string _getValue(std::string const& line);
};

#endif /* !MODULERAM_H_ */

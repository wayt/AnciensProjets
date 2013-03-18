/*
** ModuleKernelVersion.h for Modules in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src/Modules
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 16:23:17 2013 maxime ginters
** Last update Tue Jan 29 16:25:55 2013 maxime ginters
*/

#ifndef MODULEKERNELVERSION_H_
# define MODULEKERNELVERSION_H_

#include "AMonitorModule.h"
#include "AModuleCore.h"

class ModuleKernelVersion : public AMonitorModule
{
public:
    ModuleKernelVersion(AModuleCore::DisplayMode mode = AModuleCore::MODE_NCURSES, AModuleCore::DisplayType type = AModuleCore::TYPE_TEXT);
    virtual ~ModuleKernelVersion();

    void refresh();
};

#endif /* !MODULEKERNELVERSION_H_ */

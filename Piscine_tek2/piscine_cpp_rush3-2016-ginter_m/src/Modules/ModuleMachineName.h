/*
** ModuleMachineName.h for Modules in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src/Modules
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 15:12:19 2013 maxime ginters
** Last update Tue Jan 29 15:43:40 2013 maxime ginters
*/

#ifndef MODULEMACHINENAME_H_
# define MODULEMACHINENAME_H_

#include "AMonitorModule.h"
#include "AModuleCore.h"

class ModuleMachineName : public AMonitorModule
{
public:
    ModuleMachineName(AModuleCore::DisplayMode mode = AModuleCore::MODE_NCURSES, AModuleCore::DisplayType type = AModuleCore::TYPE_TEXT);
    virtual ~ModuleMachineName();

    void refresh();
};

#endif /* !MODULEMACHINENAME_H_ */

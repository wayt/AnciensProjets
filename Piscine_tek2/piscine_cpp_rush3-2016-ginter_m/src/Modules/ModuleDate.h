/*
** ModuleDate.h for Modules in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src/Modules
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 19:53:35 2013 maxime ginters
** Last update Tue Jan 29 19:56:50 2013 maxime ginters
*/

#ifndef MODULEDATE_H_
# define MODULEDATE_H_

#include "AMonitorModule.h"
#include "AModuleCore.h"

class ModuleDate : public AMonitorModule
{
public:
    ModuleDate(AModuleCore::DisplayMode mode = AModuleCore::MODE_NCURSES, AModuleCore::DisplayType type = AModuleCore::TYPE_TEXT);
    virtual ~ModuleDate();

    void refresh();
};

#endif /* !MODULEDATE_H_ */

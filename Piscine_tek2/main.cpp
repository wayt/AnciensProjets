/*
** main.cpp for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 00:19:48 2013 fabien casters
** Last update Wed Jan 30 00:53:23 2013 vincent leroy
*/

#include <unistd.h>
#include "AModuleCore.h"
#include "ModuleCoreQT.h"
#include "ModuleCoreNCurses.h"
#include "ModuleRAM.h"

int main(int ac, char **av)
{
    AModuleCore::DisplayMode mode = AModuleCore::MODE_NCURSES;

    if (ac == 2 && av[1][0] == 'q' && av[1][1] == 't')
        mode = AModuleCore::MODE_QT;

    AModuleCore* core;

    if (mode == AModuleCore::MODE_QT)
        core = new ModuleCoreQT;
    else
        core = new ModuleCoreNCurses;

    core->addModule(new ModuleRAM(core->getMode(), AModuleCore::TYPE_TEXT));
    core->addModule(new ModuleRAM(core->getMode(), AModuleCore::TYPE_TEXT));
    core->addModule(new ModuleRAM(core->getMode(), AModuleCore::TYPE_TEXT));
    core->addModule(new ModuleRAM(core->getMode(), AModuleCore::TYPE_TEXT));

    core->init();
    while(core->isRunning())
    {
        core->refresh();
        core->display();
        sleep(1);
    }

    return 0;
}

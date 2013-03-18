/*
** main.cpp for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 00:19:48 2013 fabien casters
** Last update Wed Jan 30 03:28:19 2013 vincent leroy
*/

#include <unistd.h>
#include "AModuleCore.h"
#include "ModuleCoreQT.h"
#include "ModuleCoreNCurses.h"
#include "ModuleRAM.h"
#include "config.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == 'q' && av[1][1] == 't')
    {
        std::cout << "Dodo" << std::endl;
    }

    AModuleCore* core = new ModuleCoreNCurses;

    std::string file = ac > 1 ? av[1] : "config.cfg";
    if (!config(file, core))
    {
        delete core;
        std::cout << "Unable to open file " << file << std::endl;
        return 1;
    }

    core->init();
    while(core->isRunning())
    {
        core->refresh();
        core->display();
        sleep(1);
    }
    delete core;

    return 0;
}

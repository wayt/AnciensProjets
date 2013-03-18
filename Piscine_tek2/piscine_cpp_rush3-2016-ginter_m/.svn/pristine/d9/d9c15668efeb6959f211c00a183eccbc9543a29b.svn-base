/*
** Config.cpp for src in /home/leroy_v/github/MyGKrellM/src
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Wed Jan 30 02:10:26 2013 vincent leroy
** Last update Wed Jan 30 03:21:37 2013 vincent leroy
*/

#include <iostream>
#include <fstream>
#include "config.h"
#include "AMonitorModule.h"
#include "ModuleCPU.h"
#include "ModuleRAM.h"
#include "ModuleNetwork.h"
#include "ModuleDate.h"
#include "ModuleKernelVersion.h"
#include "ModuleMachineName.h"
#include "Utils.h"

//type : texte graph barre
//cpu type num
//ram type
//net type reseau
//dat
//ker
//nam

AModuleCore::DisplayType str_to_type(std::string const &type)
{
    if (type == "text")
        return AModuleCore::TYPE_TEXT;
    else if (type == "graph")
        return AModuleCore::TYPE_GRAPH;
    else
        return AModuleCore::TYPE_BARRE;
}

bool config(std::string const &filename, AModuleCore *core)
{
    std::ifstream file(filename.c_str());

    if (!file)
        return false;

    std::string line;
    std::string type;
    while (getline(file, line))
    {
        IMonitorModule *mod = NULL;

        if (line.size() < 3)
            continue;

        if (line.compare(0, 3, "cpu") == 0)
        {
            if (line.size() < 8)
                continue;
            type = line.substr(4, 5);
            mod = new ModuleCPU(to_int(line.c_str() + 9), AModuleCore::MODE_NCURSES, str_to_type(type));
        }
        else if (line.compare(0, 3, "ram") == 0)
        {
            if (line.size() < 8)
                continue;
            type = line.substr(3, 5);
            mod = new ModuleRAM(AModuleCore::MODE_NCURSES, str_to_type(type));
        }
        else if (line.compare(0, 3, "net") == 0)
        {
            if (line.size() < 8)
                continue;
            type = line.substr(3, 5);
            mod = new ModuleNetwork(line.substr(10), AModuleCore::MODE_NCURSES, str_to_type(type));
        }
        else if (line.compare(0, 3, "dat") == 0)
        {
            mod = new ModuleDate(AModuleCore::MODE_NCURSES, AModuleCore::TYPE_TEXT);
        }
        else if (line.compare(0, 3, "ker") == 0)
        {
            mod = new ModuleKernelVersion(AModuleCore::MODE_NCURSES, AModuleCore::TYPE_TEXT);
        }
        else if (line.compare(0, 3, "nam") == 0)
        {
            mod = new ModuleMachineName(AModuleCore::MODE_NCURSES, AModuleCore::TYPE_TEXT);
        }

        if (mod)
            core->addModule(mod);
    }

    return true;
}

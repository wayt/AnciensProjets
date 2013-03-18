/*
** main.cpp for abstractVM in /home/vaga/Projects/tek2/abstractVM
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Wed Feb 13 14:06:03 2013 fabien casters
** Last update Fri Feb 22 12:47:23 2013 maxime ginters
*/

#include <fstream>
#include "Config.h"
#include "VMCore.h"
#include "VMParser.h"

int main(int ac, char **av)
{
    sConfig->addParam("-v", "--verbose", "Verbose", TYPE_FLAG, NULL);
    sConfig->setCanTakeFile(true);
    try
    {
        sConfig->parseParam(ac, av);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    VMCore core;

    if (sConfig->hasFlag("-v"))
        core.setVerbose(true);
    if (sConfig->getValuesList().size() > 0)
        core.setPath(sConfig->getValuesList().front());
    try
    {
        core.exec();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

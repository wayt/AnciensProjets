/*
** DisplayFactory.hpp for src in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 10:48:55 2013 maxime ginters
** Last update Tue Jan 29 21:51:58 2013 fabien casters
*/

#ifndef DISPLAYFACTORY_H_
# define DISPLAYFACTORY_H_

#include <map>
#include "IMonitorDisplay.h"
#include "AModuleCore.h"
#include "NCursesGraph.h"
#include "NCursesText.h"
#include "NCursesBarre.h"
#include "QTGraph.h"
#include "QTText.h"
#include "QTBarre.h"

class DisplayFactory
{
public:
    IMonitorDisplay* createDisplay(AModuleCore::DisplayMode mode, AModuleCore::DisplayType type)
    {
        return (this->*_map[mode][type])();
    }

    template<class T>
    IMonitorDisplay* create()
    {
        return new T;
    }

    static DisplayFactory* Instance()
    {
        static DisplayFactory* _instance;
        if (!_instance)
            _instance = new DisplayFactory;
        return _instance;
    }

private:
    std::map<AModuleCore::DisplayMode, std::map<AModuleCore::DisplayType, IMonitorDisplay* (DisplayFactory::*)()> > _map;

    DisplayFactory() : _map()
    {
        _map[AModuleCore::MODE_NCURSES][AModuleCore::TYPE_GRAPH] = &DisplayFactory::create<NCursesGraph>;
        _map[AModuleCore::MODE_NCURSES][AModuleCore::TYPE_TEXT] = &DisplayFactory::create<NCursesText>;
        _map[AModuleCore::MODE_NCURSES][AModuleCore::TYPE_BARRE] = &DisplayFactory::create<NCursesBarre>;
        _map[AModuleCore::MODE_QT][AModuleCore::TYPE_GRAPH] = &DisplayFactory::create<QTGraph>;
        _map[AModuleCore::MODE_QT][AModuleCore::TYPE_TEXT] = &DisplayFactory::create<QTText>;
        _map[AModuleCore::MODE_QT][AModuleCore::TYPE_BARRE] = &DisplayFactory::create<QTBarre>;
    }

};

#define sDisplayFactory DisplayFactory::Instance()

#endif /* !DISPLAYFACTORY_H_ */

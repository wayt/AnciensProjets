/*
** ModuleCoreQT.cpp for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 14:43:41 2013 fabien casters
** Last update Wed Jan 30 01:45:49 2013 vincent leroy
*/

#include "ModuleCoreQT.h"

ModuleCoreQT::ModuleCoreQT()
    : AModuleCore(AModuleCore::MODE_QT)
{
    char **title;

    title = new char*[2];
    title[0] = strdup("./imWatchingU");
    title[1] = NULL;

    int *ac = new int;
    *ac = 1;
    _app = new QApplication(*ac, title);
    _main = new QWidget;
    _layout = new QGridLayout(_main);
    _main->show();
}

ModuleCoreQT::~ModuleCoreQT()
{
}

void ModuleCoreQT::init()
{
    int x = 0;
    int y = 0;

    for (std::list<IMonitorModule*>::iterator it = _modules.begin(); it != _modules.end(); ++it)
    {
        _layout->addWidget((*it)->getDisplay()->init(_main), x, y);
        if (++y >= 5)
        {
            y = 0;
            ++x;
        }
    }
}

void ModuleCoreQT::display()
{
    _app->processEvents();
    for (std::list<IMonitorModule*>::iterator it = _modules.begin(); it != _modules.end(); (*it)->display(), ++it);
}

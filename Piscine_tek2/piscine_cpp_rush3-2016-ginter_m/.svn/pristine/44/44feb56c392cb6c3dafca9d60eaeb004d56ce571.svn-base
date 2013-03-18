/*
** ModuleCoreNCurses.cpp for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 14:43:41 2013 fabien casters
** Last update Wed Jan 30 02:49:18 2013 fabien casters
*/

#include <cstdlib>
#include "ModuleCoreNCurses.h"

ModuleCoreNCurses::ModuleCoreNCurses()
    : AModuleCore(AModuleCore::MODE_NCURSES), _window(NULL)
{
    if ((_window = ::initscr()) == NULL)
    {
        std::cerr << "Fail init my window" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    start_color();
    curs_set(0);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    noecho();
    nodelay(_window, 1);
}

ModuleCoreNCurses::~ModuleCoreNCurses()
{
    ::endwin();
}

void ModuleCoreNCurses::init()
{
    int y = 0, x = 0;
    int maxY, maxX;
    getmaxyx(_window, maxY, maxX);

    for (std::list<IMonitorModule*>::iterator it = _modules.begin(); it != _modules.end(); ++it)
    {
       (*it)->getDisplay()->init(_window, y, x);
       y += 8;
       if (y >= maxY)
       {
           y = 0;
           x += 51;
       }
       if (x >= maxX)
       {
           _running = false;
       }
    }
}

void ModuleCoreNCurses::display()
{
    if (getch() == 113)
        _running = false;
    for (std::list<IMonitorModule*>::iterator it = _modules.begin(); it != _modules.end(); ++it)
    {
       (*it)->getDisplay()->display();
    }
    ::refresh();
}

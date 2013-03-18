/*
** ModuleCoreNCurses.h for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 14:39:41 2013 fabien casters
** Last update Tue Jan 29 17:20:50 2013 fabien casters
*/

#ifndef MODULECORENCURSES_H_
# define MODULECORENCURSES_H_

#include <cstdlib>
#include <curses.h>
#include "AModuleCore.h"

class ModuleCoreNCurses : public AModuleCore
{
public:
    ModuleCoreNCurses();
    virtual ~ModuleCoreNCurses();
    void init();
    void display();
private:
    WINDOW *_window;
};

#endif

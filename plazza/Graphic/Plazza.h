/*
** Plazza.h for  in /home/vaga/Projects/tek2/plazza/Plazza
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Mon Apr 15 17:44:35 2013 fabien casters
** Last update Sat Apr 20 19:09:08 2013 fabien casters
*/

#ifndef GRAPHIC_H_
# define GRAPHIC_H_

#include <iostream>
#include <stdexcept>
#include <list>
#include <curses.h>
#include <sstream>
#include <unistd.h>
#include <sys/ioctl.h>
#include "GKitchen.h"
#include "Pizza.h"
#include "Cook.h"

namespace Graphic
{
    class Plazza
    {
     public:
        Plazza();
        ~Plazza();
        void addKitchen(int id, int total);
        void removeKitchen(int id);
        void setCookState(int id_kitchen, int id_cook, StateCook state);
        void setIngredientCount(int id_kitchen, Ingredients id_ingredient, int nb);
        void draw() const;
        void setRemaining(int id_kitchen, unsigned int val);
        void updateInput();
        void resize();
     private:
        WINDOW *window;
        std::list<GKitchen*> _kitchens;
        std::stringstream _input;
        int _width;
        int _height;
        int _scroll;
    };
}

#endif

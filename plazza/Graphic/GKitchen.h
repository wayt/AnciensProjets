/*
** Kitchen.h for  in /home/vaga/Projects/tek2/plazza/Graphic
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Mon Apr 15 18:00:29 2013 fabien casters
** Last update Sat Apr 20 19:30:02 2013 fabien casters
*/

#ifndef GKITCHEN_H_
# define GKITCHEN_H_

#include <stdexcept>
#include <iostream>
#include <map>
#include <utility>
#include <curses.h>
#include "SharedDefines.h"
#include "Pizza.h"
#include "Cook.h"

#define KWIDTH 30
#define KHEIGHT 16

namespace Graphic
{
    class GKitchen
    {
     public:
        GKitchen(WINDOW *win, int id);
        ~GKitchen();
        void addCook(int id);
        void setCookState(int id, StateCook);
        void setIngredientCount(Ingredients, int);
        int getId() const;
        void draw(int x, int y) const;
        void clear() const;
        void setRemaining(unsigned int val);
     private:
        std::map<int,StateCook> _cooks;
        std::map<Ingredients, int> _ingredients;
        std::map<Ingredients, std::string> _namesIngredient;
        int _id;
        WINDOW *_window;
        unsigned int _remaining;
    };
}

#endif

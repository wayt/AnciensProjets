/*
** Kitchen.cpp for  in /home/vaga/Projects/tek2/plazza/Graphic
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Mon Apr 15 18:01:24 2013 fabien casters
** Last update Sat Apr 20 19:29:44 2013 fabien casters
*/

#include <sstream>
#include "GKitchen.h"

namespace Graphic
{
    GKitchen::GKitchen(WINDOW *parent, int id)
        : _id(id), _remaining(0)
    {
        if ((_window = subwin(parent, KHEIGHT, KWIDTH, 0, 0)) == NULL)
            throw std::logic_error("graphic: subwin fail !\n");
        wborder(_window, 0, 0, 0, 0, 0, 0, 0, 0);

        _namesIngredient[DOE] = "Doe";
        _namesIngredient[TOMATO] = "Tomato";
        _namesIngredient[GRUYERE] = "Gruyere";
        _namesIngredient[HAM] = "Ham";
        _namesIngredient[MUSHROOMS] = "Mushrooms";
        _namesIngredient[STEAK] = "Steak";
        _namesIngredient[EGGPLANT] = "Eggplant";
        _namesIngredient[GOAT_CHEESE] = "Goat Cheese";
        _namesIngredient[CHIEF_LOVE] = "Chief Love";

        _ingredients[DOE] = 0;
        _ingredients[TOMATO] = 0;
        _ingredients[GRUYERE] = 0;
        _ingredients[HAM] = 0;
        _ingredients[MUSHROOMS] = 0;
        _ingredients[STEAK] = 0;
        _ingredients[EGGPLANT] = 0;
        _ingredients[GOAT_CHEESE] = 0;
        _ingredients[CHIEF_LOVE] = 0;
    }

    GKitchen::~GKitchen()
    {
        wclear(_window);
        wrefresh(_window);
    }

    void GKitchen::addCook(int id)
    {
        _cooks[id] = WAIT_PIZZA;
    }

    void GKitchen::setCookState(int id, StateCook state)
    {
        _cooks[id] = state;
    }

    void GKitchen::setIngredientCount(Ingredients ing, int count)
    {
        _ingredients[ing] = count;
    }

    int GKitchen::getId() const
    {
        return _id;
    }

    void GKitchen::draw(int x, int y) const
    {
        std::stringstream title;
        std::map<int, StateCook>::const_iterator it;
        std::map<Ingredients, int>::const_iterator it2;

        mvwin(_window, y + 1, x);
        wborder(_window, 0, 0, 0, 0, 0, 0, 0, 0);
        title << "Kitchen #" << _id;
        mvwaddstr(_window, 0, 3, title.str().c_str());

        int i = 0;
        for(it = _cooks.begin(); it != _cooks.end(); ++it)
        {
            wattron(_window, A_BOLD | COLOR_PAIR(it->second + 1));
            mvwaddstr(_window, 2, 3 + i * 2, "#");
            wattroff(_window, A_BOLD | COLOR_PAIR(it->second + 1));
            ++i;
        }
        mvwprintw(_window, 4, 4, "Pizza(s) : %4u", _remaining);
        i = 0;
        for(it2 = _ingredients.begin(); it2 != _ingredients.end(); ++it2)
        {
            mvwaddstr(_window, 6 + i, 2, _namesIngredient.find(it2->first)->second.c_str());
            mvwaddstr(_window, 6 + i, 13, ":");
            mvwprintw(_window, 6 + i, 15, "%4d", it2->second);
            ++i;
        }
        wrefresh(_window);
    }
    void GKitchen::clear() const
    {
        wclear(_window);
    }

    void GKitchen::setRemaining(unsigned int val)
    {
        _remaining = val;
    }
}

/*
** Plazza.cpp for plazza in /home/vaga/Projects/tek2/plazza/Plazza
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Mon Apr 15 17:52:50 2013 fabien casters
** Last update Sat Apr 20 19:28:34 2013 fabien casters
*/

#include "Accueil.h"
#include "Plazza.h"

namespace Graphic
{
    Plazza::Plazza()
    {
        if ((window = initscr()) == NULL)
            throw std::logic_error("graphic: initscr fail !\n");
        curs_set(0);
        start_color();
        noecho();
        nodelay(window, 1);
        keypad(window, TRUE);
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        init_pair(3, COLOR_RED, COLOR_BLACK);
        resize();
        mvwprintw(window, 0, 2, "Command: %s", _input.str().c_str());
        wrefresh(window);
        _scroll = 0;
    }

    Plazza::~Plazza()
    {
        delwin(window);
        endwin();
    }

    void Plazza::addKitchen(int id, int total)
    {
        GKitchen* kitchen = new GKitchen(window, id);
        for(int i = 1; i <= total; ++i)
            kitchen->addCook(i);
        _kitchens.push_back(kitchen);
    }

    void Plazza::setCookState(int id_kitchen, int id_cook, StateCook state)
    {
        std::list<GKitchen*>::iterator it;
        for(it = _kitchens.begin(); it != _kitchens.end(); ++it)
        {
            if ((*it)->getId() == id_kitchen)
                (*it)->setCookState(id_cook, state);
        }
    }

    void Plazza::setIngredientCount(int id_kitchen, Ingredients id_ingredient, int nb)
    {
        std::list<GKitchen*>::iterator it;
        for(it = _kitchens.begin(); it != _kitchens.end(); ++it)
        {
            if ((*it)->getId() == id_kitchen)
                (*it)->setIngredientCount(id_ingredient, nb);
        }
    }

    void Plazza::removeKitchen(int id)
    {
        std::list<GKitchen*>::iterator it;
        for(it = _kitchens.begin(); it != _kitchens.end(); ++it)
        {
            if ((*it)->getId() == id)
            {
                GKitchen* save = *it;
                _kitchens.erase(it);
                delete save;
                return;
            }
        }
    }

    void Plazza::resize()
    {
        struct winsize win;

        ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
        _height = win.ws_row;
        _width = win.ws_col;
        wclear(window);
    }

    void Plazza::draw() const
    {
        std::list<GKitchen*>::const_iterator it;
        int maxX = _width / KWIDTH;
        int x = 0;
        int y = 0;

        for(it = _kitchens.begin(); it != _kitchens.end(); ++it)
        {
            if ((*it)->getId() > maxX * _scroll)
            {
                x = KWIDTH * (((*it)->getId() - maxX * _scroll - 1) % maxX);
                y = KHEIGHT * (((*it)->getId() - maxX * _scroll - 1) / maxX);
                if (x + KWIDTH <= _width && y + KHEIGHT <= _height)
                    (*it)->draw(x, y);
                else
                    (*it)->clear();
            }
        }
        mvwprintw(window, 0, 2, "Command: %*s", _input.str().length(), _input.str().c_str());
    }

    void Plazza::updateInput()
    {
        int32 key = wgetch(window);
        if (key != ERR)
        {
            if (key == 10)
            {
                mvwprintw(window, 0, 2, "Command: %*s", _input.str().length(), "");
                sAccueil->readCommandList(_input.str());
                _input.str("");
            }
            else if (key >= 32 && key < 127)
            {
                _input << (char)key;
                mvwprintw(window, 0, 2, "Command: %s", _input.str().c_str());
            }
            else if (key == KEY_UP)
            {
                if (_scroll > 0)
                    _scroll--;
                wclear(window);
            }
            else if (key == KEY_DOWN)
            {
                _scroll++;
                wclear(window);
            }
            wrefresh(window);
        }
    }

    void Plazza::setRemaining(int id_kitchen, unsigned int val)
    {
        std::list<GKitchen*>::iterator it;
        for(it = _kitchens.begin(); it != _kitchens.end(); ++it)
        {
            if ((*it)->getId() == id_kitchen)
                (*it)->setRemaining(val);
        }
    }
}

/*
** GraphicNCurses.h for ncurses in /Storage/Epitech/Nibbler/libraries/ncurses
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Mar 14 15:19:10 2013 maxime ginters
** Last update Fri Mar 22 17:02:55 2013 maxime ginters
*/

#ifndef GRAPHICNCURSES_H_
# define GRAPHICNCURSES_H_

#include <curses.h>
#include <iostream>
#include "IGraphic.h"

#define WIDTH 40
#define HEIGHT 40

class GraphicNCurses : public IGraphic
{
public:
    GraphicNCurses();
    virtual ~GraphicNCurses();

    void init(int width, int height, std::string const& title);
    void draw(Resources **);
    void setTime(int value);
    void setScore(int value);
    void stop();
    int getKey();

private:
    char getCharNSetColorForResource(Resources id);
    void drowBorder();

    std::string _title;
    WINDOW* _window;
    int _bgcolor;
    int _winOffsetX;
    int _winOffsetY;
    int _height;
    int _width;
};

extern "C"
{
    IGraphic *create_graphic();
}

#endif /* !GRAPHICNCURSES_H_ */

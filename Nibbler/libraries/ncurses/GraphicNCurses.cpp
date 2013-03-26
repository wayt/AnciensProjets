/*
** GraphicNCurses.cpp for ncurses in /Storage/Epitech/Nibbler/libraries/ncurses
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Mar 14 15:32:17 2013 maxime ginters
** Last update Fri Mar 22 17:08:59 2013 maxime ginters
*/

#include <cstdlib>
#include "GraphicNCurses.h"

GraphicNCurses::GraphicNCurses() : _title(""), _window(NULL), _bgcolor(COLOR_BLACK),
    _winOffsetX(0), _winOffsetY(0), _height(0), _width(0)
{
    initscr();
}

GraphicNCurses::~GraphicNCurses()
{
    endwin();
}

void GraphicNCurses::init(int width, int height, std::string const& title)
{
    _width = width + 2;
    _height = height + 3;
    _winOffsetX = 1;
    _winOffsetY = 2;
    int startx = (COLS - _width) / 2;
    int starty = (LINES - _height) / 2;

    _title = title;
    _window = newwin(_height, _width + 20, starty, startx);
    if (_window == NULL)
    {
        std::cerr << "Error: fail to create new NCurses window" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    start_color();
    curs_set(0);
    noecho();
    nodelay(_window, 1);
    keypad(_window, TRUE);
    init_pair(1, COLOR_WHITE, _bgcolor);
    init_pair(2, COLOR_RED, _bgcolor);
    init_pair(3, COLOR_GREEN, _bgcolor);
    init_pair(4, COLOR_BLUE, _bgcolor);
    drowBorder();
    wrefresh(_window);
}

void GraphicNCurses::draw(Resources **map)
{
    for (int i = 0; i < _height - 3; ++i)
        for (int j = 0; j < _width - 2; ++j)
            mvwprintw(_window, i + _winOffsetY, j + _winOffsetX, "%c", this->getCharNSetColorForResource(map[i][j]));
    wrefresh(_window);
}
void GraphicNCurses::setTime(int value)
{
    wattron(_window, A_BOLD | COLOR_PAIR(1));
    mvwprintw(_window, 4, _width + 5, "Time : %d", value);
    wrefresh(_window);;
}

void GraphicNCurses::setScore(int value)
{
    wattron(_window, A_BOLD | COLOR_PAIR(1));
    mvwprintw(_window, 5, _width + 5, "Score : %d    ", value);
    wrefresh(_window);
}

void GraphicNCurses::stop()
{
    for (int y = 0; y < _height - 3; ++y)
        for (int x = 0; x < _width - 2; ++x)
            mvwprintw(_window, y + _winOffsetY, x + _winOffsetX, "%c", this->getCharNSetColorForResource(NONE));
    wattron(_window, A_BOLD | COLOR_PAIR(2));
    mvwprintw(_window, _winOffsetY + (_height - 4) / 2, _winOffsetX + (_width - 6) / 2, "PERDU !");
    wrefresh(_window);
    nodelay(_window, 0);
    wgetch(_window);
}

int GraphicNCurses::getKey()
{
    int key = wgetch(_window);
    if (key == ERR)
        return NO_KEY;
    switch (key)
    {
        case KEY_LEFT:
            return LEFT_ARROW;
        case KEY_RIGHT:
            return RIGHT_ARROW;
        case 27:
            return ESCAPE;
    }
    return NO_KEY;
}

char GraphicNCurses::getCharNSetColorForResource(Resources id)
{
    switch (id)
    {
        case NONE:
            return ' ';
        case WALL:
            wattron(_window, A_BOLD | COLOR_PAIR(4));
            return '#';
        case BODY:
        case HEAD:
            wattron(_window, A_BOLD | COLOR_PAIR(3));
            return id == BODY ? 'o' : 'O';
        case FOOD:
            wattron(_window, A_BOLD | COLOR_PAIR(2));
            return '@';
    }
    return (char)id;
}

void GraphicNCurses::drowBorder()
{
    wattron(_window, A_BOLD | COLOR_PAIR(1));
    mvwprintw(_window, 0, _width - _title.size() - 1, _title.c_str());
    for (int x = 0; x < _width; ++x)
    {
        mvwprintw(_window, 1, x, "-");
        mvwprintw(_window, _height - 1, x, "-");
    }
    for (int y = 2; y < _height - 1; ++y)
    {
        mvwprintw(_window, y, 0, "|");
        mvwprintw(_window, y, _width - 1, "|");
    }
}

extern "C"
{
    IGraphic *create_graphic()
    {
        return new GraphicNCurses();
    }
}


/*
** Map.cpp for core in /home/leroy_v/github/Nibbler/core
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Wed Mar 20 19:12:47 2013 vincent leroy
** Last update Thu Mar 21 10:03:55 2013 vincent leroy
*/

#include <iostream>
#include "Map.h"

Map::Map(int w, int h) :
    _head(),
    _body(),
    _w(w),
    _h(h),
    _map(NULL)
{
    _map = new Resources*[h];
    for (int i = 0; i < h; ++i)
    {
        _map[i] = new Resources[w];
        for (int j = 0; j < w; ++j)
        {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
                _map[i][j] = WALL;
            else
                _map[i][j] = NONE;
        }
    }
}

Map::Map(const Map &) :
    _head(),
    _body(),
    _w(0),
    _h(0),
    _map(NULL)
{
}

Map::~Map()
{
    if (!_map)
        return ;

    for (int i = 0; i < _h; ++i)
        delete[] _map[i];
    delete[] _map;
}

void Map::init()
{
    _head.x = _w / 2;
    _head.y = _h / 2;
    _map[_head.y][_head.x] = HEAD;
    point p;

    p.x = _head.x + 1;
    p.y = _head.y;
    _body.push_back(p);
    ++p.x;
    _body.push_back(p);
    ++p.x;
    _body.push_back(p);
    for (size_t i = 0; i < _body.size(); ++i)
        _map[_body[i].y][_body[i].x] = BODY;
    _add_food();
    _add_randomWall(_w * _h / 40);
}

bool Map::majMap(Orientation o, int &score)
{
    _move_body();
    if (o == LEFT)
        --_head.x;
    else if (o == RIGHT)
        ++_head.x;
    else if (o == UP)
        --_head.y;
    else
        ++_head.y;

    if (_map[_head.y][_head.x] == WALL || _map[_head.y][_head.x] == BODY)
    {
        _map[_head.y][_head.x] = HEAD;
        return false;
    }
    else if (_map[_head.y][_head.x] == FOOD)
    {
        _map[_head.y][_head.x] = HEAD;
        if (!_add_body())
            return false;
        _add_food();
        score += 100;
    }

    _map[_head.y][_head.x] = HEAD;
    return true;
}

Resources** Map::getMap() const
{
    return _map;
}

void Map::_move_body()
{
    _map[_body[_body.size() - 1].y][_body[_body.size() - 1].x] = NONE;
    for (size_t i = _body.size() - 1; i > 0; --i)
    {
        _body[i].x = _body[i - 1].x;
        _body[i].y = _body[i - 1].y;
        _map[_body[i].y][_body[i].x] = BODY;
    }
    _body[0].x = _head.x;
    _body[0].y = _head.y;
    _map[_body[0].y][_body[0].x] = BODY;
}

bool Map::_add_body()
{
    point newBody;
    point last;

    last = _body[_body.size() - 1];
    newBody = last;

    if (_map[last.y][last.x + 1] == NONE)
        ++newBody.x;
    else if (_map[last.y][last.x - 1] == NONE)
        --newBody.x;
    else if (_map[last.y + 1][last.x] == NONE)
        ++newBody.y;
    else if (_map[last.y - 1][last.x] == NONE)
        --newBody.y;
    else
        return false;

    _map[newBody.y][newBody.x] = BODY;
    _body.push_back(newBody);
    return true;
}

void Map::_add_food()
{
    int x;
    int y;

    do
    {
        x = rand() % _w;
        y = rand() % _h;
    }
    while (_map[y][x] != NONE);

    _map[y][x] = FOOD;
}

void Map::_add_randomWall(int nb)
{
    int i;
    int x;
    int y;

    for (i = 0; i < nb; ++i)
    {
        do
        {
            x = rand() % _w;
            y = rand() % _h;
        }
        while (_map[y][x] != NONE && x != _head.x - 1 && x != _head.x - 2);

        _map[y][x] = WALL;
    }
}

Map& Map::operator=(const Map &)
{
    return *this;
}

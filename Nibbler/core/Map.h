/*
** Map.h for core in /home/leroy_v/github/Nibbler/core
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Wed Mar 20 19:12:49 2013 vincent leroy
** Last update Thu Mar 21 10:03:00 2013 vincent leroy
*/

#ifndef MAP_H_
# define MAP_H_

#include <string>
#include <vector>
#include <cstdlib>
#include "IGraphic.h"

enum Orientation
{
    LEFT	= 0,
    RIGHT	= 1,
    UP		= 2,
    DOWN	= 3
};

class Map
{
    public:
        explicit Map(int w, int h);
        virtual ~Map();

        void init();
        bool majMap(Orientation o, int &score);
        Resources** getMap() const;

    private:
        struct point
        {
            int x;
            int y;
        };

        Map(const Map &);
        Map& operator=(const Map &);

        void _move_body();
        bool _add_body();
        void _add_food();
        void _add_randomWall(int nb);

        point _head;
        std::vector<point> _body;
        int _w;
        int _h;
        Resources **_map;
};

#endif /* !MAP_H_ */

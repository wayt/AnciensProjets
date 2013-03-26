/*
** main.cpp for core in /home/leroy_v/github/Nibbler/core
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Wed Mar 20 13:09:22 2013 vincent leroy
** Last update Fri Mar 22 16:42:19 2013 maxime ginters
*/

#include <iostream>
#include <string>
#include <sstream>
#include <dlfcn.h>
#include <ctime>
#include <unistd.h>
#include "Map.h"

bool recup_size(char **av, int &w, int &h)
{
    std::istringstream issw(av[1]);
    std::istringstream issh(av[2]);

    issw >> w;
    issh >> h;
    if (w < 20 || w > 60 || h < 20 || h > 50)
    {
        std::cerr << "Wring size enterred: 20 <= w <= 60 and 20 <= h <= 50" << std::endl;
        return false;
    }
    return true;
}

IGraphic* recup_graph(char *lib, void **handle)
{
    IGraphic* (*creator)();

    if ((*handle = dlopen(lib, RTLD_LAZY)) == NULL)
        return NULL;
    if ((creator = reinterpret_cast<IGraphic* (*)()>(dlsym(*handle, "create_graphic"))) == NULL)
        return NULL;
    return creator();
}

void change_orientation(int key, Orientation &o)
{
    if (key == 1 && o == UP)
        o = LEFT;
    else if (key == 2 && o == DOWN)
        o = LEFT;
    else if (key == 1 && o == DOWN)
        o = RIGHT;
    else if (key == 2 && o == UP)
        o = RIGHT;
    else if (key == 1 && o == LEFT)
        o = DOWN;
    else if (key == 2 && o == RIGHT)
        o = DOWN;
    else if (key == 1 && o == RIGHT)
        o = UP;
    else if (key == 2 && o == LEFT)
        o = UP;
}

bool game_loop(IGraphic *graph, Map *map)
{
    Orientation o = LEFT;
    int realKey;
    int key;
    int i;
    int score;
    float t;
    bool run = true;

    i = 0;
    score = 0;
    t = 0.0f;
    realKey = 0;
    while (run && (key = graph->getKey()) != 3)
    {
        if (key != 0 && realKey == 0)
            realKey = key;

        if (++i >= 200)
        {
            change_orientation(realKey, o);
            realKey = 0;
            i = 0;
            run = map->majMap(o, score);
            graph->setScore(score);
            graph->setTime(t);
            graph->draw(map->getMap());
        }
        usleep(1000);
        t += 0.001f;
    }

    return run;
}

int main(int ac, char **av)
{
    int w;
    int h;
    void *handle;
    IGraphic *graph;
    Map *map;

    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <width> <height> <lib_nibbler_XXX.so>" << std::endl;
        return 1;
    }

    if (!recup_size(av, w, h))
        return 1;
    if ((graph = recup_graph(av[3], &handle)) == NULL)
    {
        std::cerr << dlerror() << std::endl;
        return 1;
    }

    srand(time(NULL));

    map = new Map(w, h);
    map->init();
    graph->init(w, h, "Nibbler");

    if (!game_loop(graph, map))
        graph->stop();

    delete map;
    delete graph;
    dlclose(handle);

    return 0;
}

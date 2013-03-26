/*
** GraphicOpenGL.h for nibbler in /home/vaga/Projects/tek2/nibbler/libraries/opengl
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Mar 19 14:28:53 2013 fabien casters
** Last update Sat Mar 23 16:07:21 2013 fabien casters
*/

#ifndef GRAPHICOPENGL_H_
# define GRAPHICOPENGL_H_

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "IGraphic.h"
#include "EventSDL.h"

class GraphicOpenGL : public IGraphic
{
 public:
    static GraphicOpenGL *getInstance();
    void init(int width, int height, const std::string &title);
    void draw(Resources **);
    void camera() const;
    void drawCube(int x, int y, Resources res) const;
    void setTime(int value);
    void setScore(int value);
    void stop();
    int getKey();
    static void displayWrapper();
    void display() const;
 private:
    GraphicOpenGL();
    int _width;
    int _height;
    int _time;
    int _score;
    Resources **_map;
    EventSDL _event;
};

extern "C"
{
    IGraphic *create_graphic();
}
#endif

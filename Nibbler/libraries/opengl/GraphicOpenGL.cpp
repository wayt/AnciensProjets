/*
** GraphicOpenGL.cpp for nibbler in /home/vaga/Projects/tek2/nibbler/libraries/opengl
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Mar 19 14:33:07 2013 fabien casters
** Last update Sat Mar 23 16:39:44 2013 fabien casters
*/

#include "GraphicOpenGL.h"

GraphicOpenGL *GraphicOpenGL::getInstance()
{
    static GraphicOpenGL *_instance = NULL;

    if (_instance == NULL)
        _instance = new GraphicOpenGL();
    return _instance;
}

GraphicOpenGL::GraphicOpenGL()
    : _width(0), _height(0), _time(0), _score(0), _map(NULL), _event()
{
}

void GraphicOpenGL::init(int width, int height, const std::string &title)
{
    _width = width;
    _height = height;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption(title.c_str(), NULL);
    SDL_SetVideoMode(1024, 800, 32, SDL_OPENGL);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,(double)1024/800,1,1000);
}

void GraphicOpenGL::draw(Resources **tab)
{
    _map = tab;
    display();
    _event.updateEvent(false);
}

void GraphicOpenGL::setTime(int value)
{
    _time = value;
}

void GraphicOpenGL::setScore(int value)
{
    _score = value;
}

void GraphicOpenGL::stop()
{

}

int GraphicOpenGL::getKey()
{
    return _event.getKey();
}

void GraphicOpenGL::displayWrapper()
{
    getInstance()->display();
}

void GraphicOpenGL::drawCube(int x, int y, Resources res) const
{
    glBegin(GL_QUADS);
    if (res == WALL)
        glColor3d(0.4, 0.4, 0.4);
    else if (res == BODY)
        glColor3d(0.0, 0.5, 0.0);
    else if (res == HEAD)
        glColor3d(0.0, 0.6, 0.0);
    else if (res == FOOD)
        glColor3d(1.0, 0.0, 0.0);
    glVertex3i(x,     y,     1); // dessus
    glVertex3i(x,     y + 1, 1);
    glVertex3i(x + 1, y + 1, 1);
    glVertex3i(x + 1, y,     1);

    glVertex3i(x + 1, y,     1); // face
    glVertex3i(x + 1, y + 1, 1);
    glVertex3i(x + 1, y + 1, 0);
    glVertex3i(x + 1, y,     0);

    glVertex3i(x, y,     1); // face
    glVertex3i(x, y + 1, 1);
    glVertex3i(x, y + 1, 0);
    glVertex3i(x, y,     0);

    glVertex3i(x,     y,     1); // left
    glVertex3i(x,     y,     0);
    glVertex3i(x + 1, y,     0);
    glVertex3i(x + 1, y,     1);

    glVertex3i(x,     y + 1, 1); // right
    glVertex3i(x,     y + 1, 0);
    glVertex3i(x + 1, y + 1, 0);
    glVertex3i(x + 1, y + 1, 1);

    glEnd();
}

void GraphicOpenGL::camera() const
{
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            if (_map[y][x] == HEAD)
            {
                //gluLookAt(_width, y, 20, x, y, 0, 0, 0, 1);
                gluLookAt(y, _width, 20, y, x, 0, 0, 0, 1);
                return ;
            }
        }
    }
}

void GraphicOpenGL::display() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera();

    glBegin(GL_QUADS);
    glColor3d(1, 1, 1);
    glVertex3i(0, 0, 0);        // plan
    glVertex3i(0, _width, 0);
    glVertex3i(_height, _width, 0);
    glVertex3i(_height, 0, 0);
    glEnd();

    if (_map != NULL)
    {
        for (int y = 0; y < _height; ++y)
        {
            for (int x = 0; x < _width; ++x)
            {
                if (_map[y][x] != NONE)
                    this->drawCube(y, x, _map[y][x]);
            }
        }
    }
    glFlush();
    SDL_GL_SwapBuffers();
}

extern "C"
{
    IGraphic *create_graphic()
    {
        return GraphicOpenGL::getInstance();
    }
}

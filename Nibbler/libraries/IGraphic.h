/*
** IGraphic.h for  in /home/vaga/Projects/tek2/nibbler/libraries/opengl/tests
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Thu Mar 07 14:09:17 2013 fabien casters
** Last update Fri Mar 22 16:44:01 2013 maxime ginters
*/

#ifndef IGRAPHIC_H_
# define IGRAPHIC_H_

#include <string>

enum Resources
{
    NONE            = 0,
    WALL            = 1,
    BODY            = 2,
    HEAD            = 3,
    FOOD            = 4
};

enum Key
{
    NO_KEY          = 0,
    LEFT_ARROW      = 1,
    RIGHT_ARROW     = 2,
    ESCAPE          = 3
};

class IGraphic
{
public:
    virtual ~IGraphic() {}
    virtual void init(int width, int height, const std::string &title) = 0;
    virtual void draw(Resources **) = 0;
    virtual void setTime(int value) = 0;
    virtual void setScore(int value) = 0;
    virtual void stop() = 0;
    virtual int getKey() = 0;
};

#endif


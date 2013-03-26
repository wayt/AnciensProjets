/*
** EventSDL.cpp for Nibbler in /home/leroy_v/Epitech/projet_tek2/Nibbler
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Thu Mar 07 20:22:13 2013 vincent leroy
** Last update Fri Mar 22 15:55:25 2013 fabien casters
*/

#include "EventSDL.h"

EventSDL::EventSDL() :
    _event(),
    _key(),
    _mouseX(0),
    _mouseY(0),
    _mouseButton(),
    _quit(false)
{
}

EventSDL::~EventSDL()
{
}

int EventSDL::getKey()
{
    updateEvent(false);
    if (_key[SDLK_LEFT])
    {
        _key[SDLK_LEFT] = false;
        return LEFT_ARROW;
    }
    else if (_key[SDLK_RIGHT])
    {
        _key[SDLK_RIGHT] = false;
        return RIGHT_ARROW;
    }
    else if (_key[SDLK_ESCAPE] || _quit)
    {
        _key[SDLK_ESCAPE] = false;
        return ESCAPE;
    }
    return NO_KEY;
}

bool EventSDL::hasKey(int key) const
{
    return _key[key];
}

void EventSDL::setKey(int key, bool state)
{
    _key[key] = state;
}

int EventSDL::getMouseX() const
{
    return _mouseX;
}

int EventSDL::getMouseY() const
{
    return _mouseY;
}

bool EventSDL::hasMouseButton(int button) const
{
    return _mouseButton[button];
}

void EventSDL::setMouseButton(int button, bool state)
{
    _mouseButton[button] = state;
}

bool EventSDL::hasQuit() const
{
    return _quit;
}

void EventSDL::setQuit(bool state)
{
    _quit = state;
}

void EventSDL::updateEvent(bool wait)
{
    if (wait)
        SDL_WaitEvent(&_event);
    else
        SDL_PollEvent(&_event);

    if (_event.type == SDL_KEYDOWN)
        _key[_event.key.keysym.sym] = true;
    else if (_event.type == SDL_KEYUP)
        _key[_event.key.keysym.sym] = false;
    else if (_event.type == SDL_MOUSEMOTION)
    {
        _mouseX = _event.motion.x;
        _mouseY = _event.motion.y;
    }
    else if (_event.type == SDL_MOUSEBUTTONDOWN)
        _mouseButton[_event.button.button] = true;
    else if (_event.type == SDL_MOUSEBUTTONUP)
        _mouseButton[_event.button.button] = false;
    else if (_event.type == SDL_QUIT)
        _quit = true;
    _event.type = 0;
}

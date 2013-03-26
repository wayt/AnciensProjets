/*
** EventSDL.h for Nibbler in /home/leroy_v/Epitech/projet_tek2/Nibbler
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Thu Mar 07 20:22:40 2013 vincent leroy
** Last update Sat Mar 23 16:13:00 2013 fabien casters
*/

#ifndef EVENTSDL_H_
# define EVENTSDL_H_

#include <SDL/SDL.h>
#include "IGraphic.h"

class EventSDL
{
    public:
        explicit EventSDL();
        virtual ~EventSDL();

        int getKey();
        bool hasKey(int key) const;
        void setKey(int key, bool state);
        int getMouseX() const;
        int getMouseY() const;
        bool hasMouseButton(int button) const;
        void setMouseButton(int button, bool state);
        bool hasQuit() const;
        void setQuit(bool state);
        void updateEvent(bool wait = true);

    private:
        SDL_Event _event;
        bool _key[SDLK_LAST];
        int _mouseX;
        int _mouseY;
        bool _mouseButton[8];
        bool _quit;
};

#endif /* !EVENTSDL_H_ */

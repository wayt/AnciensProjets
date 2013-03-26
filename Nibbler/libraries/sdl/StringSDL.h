/*
** StringSDL.h for Nibbler in /home/leroy_v/Epitech/projet_tek2/Nibbler
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Thu Mar 14 12:53:52 2013 vincent leroy
** Last update Tue Mar 19 11:49:23 2013 vincent leroy
*/

#ifndef STRINGSDL_H_
# define STRINGSDL_H_

#include <string>
#include <SDL/SDL_ttf.h>
#include "IGraphic.h"

class StringSDL
{
    public:
        explicit StringSDL();
        virtual ~StringSDL();

        void init(const std::string &font_name, int size);
        void draw(int time, int score);
        void affLose();

    private:
        StringSDL(const StringSDL &);
        StringSDL& operator=(const StringSDL &);

        void _affString(const std::string &str, SDL_Rect *pos);
        void _TTF_Error(const std::string &msg, bool quit) const;

        TTF_Font *_font;
};

#endif /* !STRINGSDL_H_ */

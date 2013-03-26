/*
** StringSDL.cpp for Nibbler in /home/leroy_v/Epitech/projet_tek2/Nibbler
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Thu Mar 14 12:53:45 2013 vincent leroy
** Last update Tue Mar 19 12:03:44 2013 vincent leroy
*/

#include <iostream>
#include <sstream>
#include "StringSDL.h"
#include "GraphicSDL.h"

StringSDL::StringSDL() :
    _font(NULL)
{
    if (TTF_Init() < 0)
        _TTF_Error("TTF_init", true);
}

StringSDL::StringSDL(const StringSDL &) :
    _font(NULL)
{
}

StringSDL::~StringSDL()
{
    TTF_CloseFont(_font);
    TTF_Quit();
}

void StringSDL::init(const std::string &font_name, int size)
{
    _font = TTF_OpenFont(font_name.c_str(), size);
    if (_font == NULL)
        _TTF_Error("TTF_OpenFont", false);
}

void StringSDL::draw(int time, int score)
{
    std::string t("time: ");
    std::string s("score: ");
    std::ostringstream oss;
    int min;
    int sec;
    int w;
    SDL_Rect pos;

    if (_font == NULL)
        return ;

    min = time / 60;
    sec = time % 60;
    oss << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec;
    t += oss.str();
    oss.str("");
    oss << score;
    s += oss.str();

    pos.x = 5;
    pos.y = 5;
    _affString(t, &pos);

    TTF_SizeText(_font, s.c_str(), &w, NULL);
    pos.x = GraphicSDL::instance()->getScreen()->w - w - 5;
    pos.y = 5;
    _affString(s, &pos);
}

void StringSDL::affLose()
{
    SDL_Rect pos;
    int w;
    int h;
    std::string lose("You lose");

    if (_font == NULL)
        return ;

    TTF_SizeText(_font, lose.c_str(), &w, &h);
    pos.x = GraphicSDL::instance()->getScreen()->w / 2 - w / 2;
    pos.y = GraphicSDL::instance()->getScreen()->h / 2 - h / 2;
    _affString(lose, &pos);
}

void StringSDL::_affString(const std::string &str, SDL_Rect *pos)
{
    SDL_Color c;
    SDL_Surface *src;

    if (str.empty())
        return ;

    c.r = 0xFF;
    c.g = 0xFF;
    c.b = 0xFF;

    src = TTF_RenderText_Blended(_font, str.c_str(), c);
    if (src == NULL)
    {
        _TTF_Error("TTF_RenderText_Blended", false);
        return ;
    }
    SDL_BlitSurface(src, NULL, GraphicSDL::instance()->getScreen(), pos);
    SDL_FreeSurface(src);
}

void StringSDL::_TTF_Error(const std::string &msg, bool quit) const
{
    std::cerr << msg << ": " << TTF_GetError() << std::endl;
    if (quit)
        exit(1);
}

StringSDL& StringSDL::operator=(const StringSDL &)
{
    return *this;
}

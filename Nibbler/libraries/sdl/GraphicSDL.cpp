/*
** GraphicSDL.cpp for Nibbler in /home/leroy_v/Epitech/projet_tek2/Nibbler
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Thu Mar 07 19:47:36 2013 vincent leroy
** Last update Thu Mar 21 09:05:08 2013 vincent leroy
*/

#include <iostream>
#include "GraphicSDL.h"

GraphicSDL::GraphicSDL() :
    _screen(NULL),
    _width(0),
    _height(0),
    _oldMap(NULL),
    _event(),
    _string(),
    _time(0),
    _score(0),
    _ressource()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        _SDL_Error("SDL_Init", true);
}

GraphicSDL::GraphicSDL(const GraphicSDL &) :
    _screen(NULL),
    _width(0),
    _height(0),
    _oldMap(NULL),
    _event(),
    _string(),
    _time(0),
    _score(0),
    _ressource()
{
}

extern "C"
{
    IGraphic* create_graphic()
    {
        return GraphicSDL::instance();
    }
}

GraphicSDL::~GraphicSDL()
{
    std::map<Resources, std::pair<Uint32, SDL_Surface*> >::iterator it;
    for (it = _ressource.begin(); it != _ressource.end(); ++it)
        SDL_FreeSurface(it->second.second);
    SDL_Quit();

    if (!_oldMap)
        return ;

    for (int i = 0; i < _height; ++i)
        delete[] _oldMap[i];
    delete[] _oldMap;
}

GraphicSDL* GraphicSDL::instance()
{
    static GraphicSDL *ins;

    if (!ins)
        ins = new GraphicSDL;
    return ins;
}

void GraphicSDL::init(int width, int height, const std::string &title)
{
    _width = width;
    _height = height;

    _oldMap = new Resources*[height];
    for (int i = 0; i < height; ++i)
    {
        _oldMap[i] = new Resources[width];
        for (int j = 0; j < width; ++j)
            _oldMap[i][j] = static_cast<Resources>(-1);
    }

    _screen = SDL_SetVideoMode(_width * SIZE, _height * SIZE + OFFSET, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (_screen == NULL)
        _SDL_Error("SDL_SetVideoMode", true);
    SDL_WM_SetCaption(title.c_str(), NULL);

    _addResources(NONE, 0x000000, "");
    _addResources(WALL, 0x0000FF, "wall.png");
    _addResources(BODY, 0x00FF00, "body.png");
    _addResources(HEAD, 0x00FFFF, "head.png");
    _addResources(FOOD, 0xFF0000, "food.png");

    _string.init(FONT_NAME, FONT_SIZE);
}

void GraphicSDL::draw(Resources **map)
{
    SDL_Rect rect;

    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
        {
            if (map[i][j] == _oldMap[i][j])
                continue;
            _oldMap[i][j] = map[i][j];
            _drawOneSquare(i, j, map[i][j]);
        }

    rect.x = 0;
    rect.y = 0;
    rect.w = _screen->w;
    rect.h = OFFSET;
    SDL_FillRect(_screen, &rect, SDL_MapRGB(_screen->format, 0x00, 0x00, 0x00));

    _string.draw(_time, _score);
    _event.updateEvent(false);
    SDL_Flip(_screen);
}

void GraphicSDL::setTime(int value)
{
    _time = value;
}

void GraphicSDL::setScore(int value)
{
    _score = value;
}

void GraphicSDL::stop()
{
    std::cout << "You lose" << std::endl;
    _string.affLose();
    SDL_Flip(_screen);
    _event.setKey(SDLK_ESCAPE, false);
    while (!_event.hasQuit() && !_event.hasKey(SDLK_ESCAPE))
        _event.updateEvent();
}

int GraphicSDL::getKey()
{
    return _event.getKey();
}

SDL_Surface* GraphicSDL::getScreen() const
{
    return _screen;
}

void GraphicSDL::_addResources(Resources id, int color, const std::string &img)
{
    SDL_Surface *_img;

    _img = NULL;
    _ressource[id].first = color;
    if (!img.empty())
        if ((_img = IMG_Load(img.c_str())) == NULL)
            _IMG_Error("IMG_Load", false);
    _ressource[id].second = _img;
}

void GraphicSDL::_drawOneSquare(int i, int j, Resources case_map)
{
    SDL_Surface *square;
    SDL_Rect rect;

    if (case_map == BODY || case_map == HEAD)
    {
        rect.x = j * SIZE + 1;
        rect.y = i * SIZE + OFFSET + 1;
    }
    else
    {
        rect.x = j * SIZE;
        rect.y = i * SIZE + OFFSET;
    }

    if (_ressource[case_map].second != NULL)
        SDL_BlitSurface(_ressource[case_map].second, NULL, _screen, &rect);
    else
    {
        if (case_map == BODY || case_map == HEAD)
            square = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE - 2, SIZE - 2, 32, 0, 0, 0, 0);
        else
            square = SDL_CreateRGBSurface(SDL_HWSURFACE, SIZE, SIZE, 32, 0, 0, 0, 0);
        if (square == NULL)
        {
            _SDL_Error("SDL_CreateRGBSurface", false);
            return ;
        }
        SDL_FillRect(square, NULL, _ressource[case_map].first);
        SDL_BlitSurface(square, NULL, _screen, &rect);
        SDL_FreeSurface(square);
    }
}

void GraphicSDL::_SDL_Error(const std::string &msg, bool quit) const
{
    std::cerr << msg << ": " << SDL_GetError() << std::endl;
    if (quit)
        exit(1);
}

void GraphicSDL::_IMG_Error(const std::string &msg, bool quit) const
{
    std::cerr << msg << ": " << IMG_GetError() << std::endl;
    if (quit)
        exit(1);
}

GraphicSDL& GraphicSDL::operator=(const GraphicSDL &)
{
    return *this;
}

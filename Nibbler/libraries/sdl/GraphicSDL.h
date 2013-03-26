/*
** GraphicSDL.h for Nibbler in /home/leroy_v/Epitech/projet_tek2/Nibbler
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Thu Mar 07 19:47:38 2013 vincent leroy
** Last update Thu Mar 21 15:58:35 2013 fabien casters
*/

#ifndef GRAPHICSDL_H_
# define GRAPHICSDL_H_

#include <string>
#include <map>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "IGraphic.h"
#include "EventSDL.h"
#include "StringSDL.h"

#define SIZE		20
#define FONT_SIZE	18
#define FONT_NAME	"arial.ttf"
#define OFFSET		(FONT_SIZE + 10)

class GraphicSDL : public IGraphic
{
    public:
        virtual ~GraphicSDL();

        static GraphicSDL* instance();

        void init(int width, int height, const std::string &title);
        void draw(Resources **map);
        void setTime(int value);
        void setScore(int value);
        void stop();
        int getKey();

        SDL_Surface* getScreen() const;

    private:
        GraphicSDL();
        GraphicSDL(const GraphicSDL &);
        GraphicSDL& operator=(const GraphicSDL &);

        void _addResources(Resources id, int color, const std::string &img);
        void _drawOneSquare(int i, int j, Resources case_map);
        void _SDL_Error(const std::string &msg, bool quit) const;
        void _IMG_Error(const std::string &msg, bool quit) const;

        SDL_Surface *_screen;
        int _width;
        int _height;
        Resources **_oldMap;
        EventSDL _event;
        StringSDL _string;
        int _time;
        int _score;
        std::map<Resources, std::pair<Uint32, SDL_Surface*> > _ressource;
};

extern "C"
{
    IGraphic* create_graphic();
}

#endif /* !GRAPHICSDL_H_ */

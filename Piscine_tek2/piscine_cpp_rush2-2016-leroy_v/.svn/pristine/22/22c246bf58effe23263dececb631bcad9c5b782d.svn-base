/*
** GiftPaper.cpp for  in /home/vaga/Projects/tek2/piscine/rush2
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sat Jan 19 20:11:52 2013 fabien casters
** Last update Sun Jan 20 02:26:26 2013 maxime ginters
*/

#include "GiftPaper.h"

GiftPaper::GiftPaper() : Wrap(TYPE_GIFTPAPER, "Un gift paper un")
{
}

bool GiftPaper::isOpen() const
{
    return true;
}

void GiftPaper::wrapMeThat(Object *obj)
{
    if (obj == NULL)
    {
        std::cout << GIFTPAPER_OBJ_EMPTY << std::endl;
        return ;
    }
    if (_obj != NULL)
    {
        std::cout << GIFTPAPER_FULL << std::endl;
        return ;
    }
    _obj = obj;
}

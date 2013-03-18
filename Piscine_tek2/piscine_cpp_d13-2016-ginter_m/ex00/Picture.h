/*
** Picture.h for ex00 in /home/fest/Epitech/Piscine_tek2/jour13/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 21 09:36:37 2013 maxime ginters
** Last update Mon Jan 21 10:27:06 2013 maxime ginters
*/

#ifndef PICTURE_H_
# define PICTURE_H_

#include <string>

class Picture
{
public:
    explicit Picture(std::string const& file = "");
    virtual ~Picture();

    bool getPictureFromFile(std::string const& file);
    std::string data;
};

#endif /* !PICTURE_H_ */

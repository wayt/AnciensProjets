/*
** PaPaXML.h for piscine_cpp_rush2-2016-leroy_v in /home/fest/Epitech/Piscine_tek2/piscine_cpp_rush2-2016-leroy_v
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sun Jan 20 01:33:34 2013 maxime ginters
** Last update Sun Jan 20 02:42:32 2013 maxime ginters
*/

#ifndef PAPAXML_H_
# define PAPAXML_H_

#include <iostream>
#include <fstream>
#include "Message.h"
#include "Object.h"
#include "Wrap.h"

class PaPaXML
{
public:
    PaPaXML(std::string const& filename);

    bool WakeUp();
    void TakeGift(Object const* obj);
    void GoSleep();

private:
    std::string _filename;
    std::ofstream _stream;
};

#endif /* !PAPAXML_H_ */

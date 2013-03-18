/*
** sickkoalalist.h for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 15:41:26 2013 maxime ginters
** Last update Mon Jan 14 16:11:16 2013 maxime ginters
*/

#ifndef SICKKOALALIST_H_
# define SICKKOALALIST_H_

#include "sickkoala.h"

class SickKoalaList
{
public:
    explicit SickKoalaList(SickKoala* koala);
    virtual ~SickKoalaList() {}

    bool isEnd();
    void append(SickKoalaList* elem);
    SickKoala* getFromName(std::string name);
    SickKoalaList* remove(SickKoalaList* node);
    SickKoalaList* removeFromName(std::string name);
    void dump();
    SickKoala* getContent();
    SickKoalaList* getNext();
private:
    SickKoala* _koala;
    SickKoalaList* _next;
};

#endif /* !SICKKOALALIST_H_ */

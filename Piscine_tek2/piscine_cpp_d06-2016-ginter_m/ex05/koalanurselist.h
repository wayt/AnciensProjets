/*
** koalanurselist.h for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 15:41:26 2013 maxime ginters
** Last update Mon Jan 14 17:53:09 2013 maxime ginters
*/

#ifndef KOALANURSELIST_H_
# define KOALANURSELIST_H_

#include "koalanurse.h"

class KoalaNurseList
{
public:
    explicit KoalaNurseList(KoalaNurse* koala);
    virtual ~KoalaNurseList() {}

    bool isEnd();
    void append(KoalaNurseList* elem);
    KoalaNurse* getFromID(int id);
    KoalaNurseList* remove(KoalaNurseList* node);
    KoalaNurseList* removeFromID(int id);
    void dump();
    KoalaNurse* getContent();
    KoalaNurseList* getNext();
private:
    KoalaNurse* _koala;
    KoalaNurseList* _next;
};

#endif /* !KOALANURSELIST_H_ */

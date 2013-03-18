/*
** koalanurselist.cpp for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 15:49:41 2013 maxime ginters
** Last update Mon Jan 14 15:49:41 2013 maxime ginters
*/

#include "koalanurselist.h"

KoalaNurseList::KoalaNurseList(KoalaNurse* koala) : _koala(koala), _next(NULL) {}

bool KoalaNurseList::isEnd()
{
    return _next == NULL;
}

void KoalaNurseList::append(KoalaNurseList* elem)
{
    if (_next)
        _next->append(elem);
    else
        _next = elem;
}

KoalaNurse* KoalaNurseList::getFromID(int id)
{
    if (_koala && _koala->getID() == id)
        return _koala;
    if (_next)
        return _next->getFromID(id);
    return NULL;
}

KoalaNurseList * KoalaNurseList::remove(KoalaNurseList* node)
{
    if (!node)
        return this;
    if (node == this)
        return _next;
    else if (_next)
    {
        if (_next == node)
            _next = _next->getNext();
        else
            _next->remove(node);
    }
    return this;
}

KoalaNurseList * KoalaNurseList::removeFromID(int id)
{
    if (_koala && _koala->getID()  == id)
        return _next;
    else if (_next)
    {
        if (_next->getContent() && _next->getContent()->getID() == id)
            _next = _next->getNext();
        else
            _next->removeFromID(id);
    }
    return this;
}

void KoalaNurseList::dump()
{
    std::cout << "Liste des infirmieres : ";
    for (KoalaNurseList* itr = this; itr != NULL; itr = itr->getNext())
    {
        std::cout << (itr == this ? "" : ", ");
        if (itr->getContent())
            std::cout << itr->getContent()->getID();
        else
            std::cout << "[NULL]";

    }
    std::cout << "." << std::endl;
}

KoalaNurse* KoalaNurseList::getContent()
{
    return _koala;
}

KoalaNurseList* KoalaNurseList::getNext()
{
    return _next;
}

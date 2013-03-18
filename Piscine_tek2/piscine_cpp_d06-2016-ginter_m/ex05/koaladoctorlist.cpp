/*
** koaladoctorlist.cpp for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 15:49:41 2013 maxime ginters
** Last update Mon Jan 14 15:49:41 2013 maxime ginters
*/

#include "koaladoctorlist.h"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor* koala) : _koala(koala), _next(NULL) {}

bool KoalaDoctorList::isEnd()
{
    return _next == NULL;
}

void KoalaDoctorList::append(KoalaDoctorList* elem)
{
    if (_next)
        _next->append(elem);
    else
        _next = elem;
}

KoalaDoctor* KoalaDoctorList::getFromName(std::string name)
{
    if (_koala && _koala->getName() == name)
        return _koala;
    if (_next)
        return _next->getFromName(name);
    return NULL;
}

KoalaDoctorList * KoalaDoctorList::remove(KoalaDoctorList* node)
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

KoalaDoctorList * KoalaDoctorList::removeFromName(std::string name)
{
    if (_koala && _koala->getName() == name)
        return _next;
    else if (_next)
    {
        if (_next->getContent() && _next->getContent()->getName() == name)
            _next = _next->getNext();
        else
            _next->removeFromName(name);
    }
    return this;
}

void KoalaDoctorList::dump()
{
    std::cout << "Liste des medecins : ";
    for (KoalaDoctorList* itr = this; itr != NULL; itr = itr->getNext())
        std::cout << (itr == this ? "" : ", ") << (itr->getContent() ? itr->getContent()->getName() : "[NULL]");
    std::cout << "." << std::endl;
}

KoalaDoctor* KoalaDoctorList::getContent()
{
    return _koala;
}

KoalaDoctorList* KoalaDoctorList::getNext()
{
    return _next;
}

/*
** koaladoctorlist.h for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 15:41:26 2013 maxime ginters
** Last update Mon Jan 14 17:27:13 2013 maxime ginters
*/

#ifndef KOALADOCTORLIST_H_
# define KOALADOCTORLIST_H_

#include "koaladoctor.h"

class KoalaDoctorList
{
public:
    explicit KoalaDoctorList(KoalaDoctor* koala);
    virtual ~KoalaDoctorList() {}

    bool isEnd();
    void append(KoalaDoctorList* elem);
    KoalaDoctor* getFromName(std::string name);
    KoalaDoctorList* remove(KoalaDoctorList* node);
    KoalaDoctorList* removeFromName(std::string name);
    void dump();
    KoalaDoctor* getContent();
    KoalaDoctorList* getNext();
private:
    KoalaDoctor* _koala;
    KoalaDoctorList* _next;
};

#endif /* !KOALADOCTORLIST_H_ */

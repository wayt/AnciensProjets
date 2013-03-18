/*
** koaladoctor.h for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 14:50:12 2013 maxime ginters
** Last update Mon Jan 14 15:23:57 2013 maxime ginters
*/

#ifndef KOALADOCTOR_H_
# define KOALADOCTOR_H_

#include <string>
#include "sickkoala.h"

class KoalaDoctor
{
public:
    explicit KoalaDoctor(std::string name);
    virtual ~KoalaDoctor();

    void diagnose(SickKoala* koala);
    void timeCheck();
    std::string getName();
private:
    std::string _name;
    bool _working;
};

#endif /* !KOALADOCTOR_H_ */

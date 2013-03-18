/*
** koalanurse.h for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 13:33:36 2013 maxime ginters
** Last update Mon Jan 14 14:32:46 2013 maxime ginters
*/

#ifndef KOALANURSE_H_
# define KOALANURSE_H_

#include <iostream>
#include <string>
#include "sickkoala.h"

class KoalaNurse
{
public:
    explicit KoalaNurse(int id);
    virtual ~KoalaNurse();

    void giveDrug(std::string drug, SickKoala* koala);
    std::string readReport(std::string file_name);
    void timeCheck();
private:
    int _id;
    bool _working;
};

#endif /* !KOALANURSE_H_ */

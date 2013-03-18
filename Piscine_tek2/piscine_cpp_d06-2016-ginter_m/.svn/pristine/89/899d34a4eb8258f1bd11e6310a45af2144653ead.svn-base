/*
** hopital.h for ex06 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex06
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 18:06:03 2013 maxime ginters
** Last update Mon Jan 14 21:15:04 2013 maxime ginters
*/

#ifndef HOPITAL_H_
# define HOPITAL_H_

#include "sickkoalalist.h"
#include "koaladoctorlist.h"
#include "koalanurselist.h"

class Hospital
{
public:
    explicit Hospital();
    virtual ~Hospital() {}

    void addDoctor(KoalaDoctorList* doc);
    void addSick(SickKoalaList* koala);
    void addNurse(KoalaNurseList* nurse);

    void run();
private:
    KoalaDoctor* getNextDoc();
    KoalaNurse* getNextNurse();

    SickKoalaList* _sickList;
    KoalaNurseList* _nurseList;
    KoalaDoctorList* _doctorList;
    SickKoalaList* _currSick;
    KoalaNurseList* _currNurse;
    KoalaDoctorList* _currDoc;
};

#endif /* !HOPITAL_H_ */

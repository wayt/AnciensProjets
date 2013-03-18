/*
** hopital.cpp for ex06 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex06
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 18:10:37 2013 maxime ginters
** Last update Mon Jan 14 18:10:37 2013 maxime ginters
*/

#include <iostream>
#include "hopital.h"
#include "koaladoctor.h"
#include "koalanurse.h"
#include "sickkoala.h"
#include "koaladoctorlist.h"
#include "koalanurselist.h"
#include "sickkoalalist.h"

Hospital::Hospital() : _sickList(NULL), _nurseList(NULL), _doctorList(NULL),
    _currSick(NULL), _currNurse(NULL), _currDoc(NULL)
{
}

void Hospital::addDoctor(KoalaDoctorList* doc)
{
    if (!doc || !doc->getContent())
        return;
    if (_doctorList && _doctorList->getFromName(doc->getContent()->getName()))
        return;
    if (!_doctorList)
        _doctorList = doc;
    else
        _doctorList->append(doc);
    std::cout << "[HOSPITAL] Doctor " << doc->getContent()->getName() << " just arrived !" << std::endl;
    doc->getContent()->timeCheck();
}

void Hospital::addSick(SickKoalaList* koala)
{
    if (!koala || !koala->getContent())
        return;
    if (_sickList && _sickList->getFromName(koala->getContent()->getName()))
        return;
    if (!_sickList)
        _sickList = koala;
    else
        _sickList->append(koala);
    std::cout << "[HOSPITAL] Patient " << koala->getContent()->getName() << " just arrived !" << std::endl;
}

void Hospital::addNurse(KoalaNurseList* nurse)
{
    if (!nurse || !nurse->getContent())
        return;
    if (_nurseList && _nurseList->getFromID(nurse->getContent()->getID()))
        return;
    if (!_nurseList)
        _nurseList = nurse;
    else
        _nurseList->append(nurse);
    std::cout << "[HOSPITAL] Nurse " << nurse->getContent()->getID() << " just arrived !" << std::endl;
    nurse->getContent()->timeCheck();
}

KoalaDoctor* Hospital::getNextDoc()
{
    if (!_currDoc && !_doctorList)
        return NULL;
    if (_currDoc)
        _currDoc = _currDoc->getNext();
    if (!_currDoc)
        _currDoc = _doctorList;
    return _currDoc->getContent();
}

KoalaNurse* Hospital::getNextNurse()
{
    if (!_currNurse && !_nurseList)
        return NULL;
    if (_currNurse)
        _currNurse = _currNurse->getNext();
    if (!_currNurse)
        _currNurse = _nurseList;
    return _currNurse->getContent();
}

void Hospital::run()
{
    if (!_sickList || !_nurseList || !_doctorList)
        return;
    std::cout << "[HOSPITAL] Debut du travail avec :" << std::endl;
    _doctorList->dump();
    _nurseList->dump();
    _sickList->dump();
    std::cout << std::endl;

    for (_currSick = _sickList; _currSick != NULL;)
    {
        if (SickKoala* koala = _currSick->getContent())
            if (KoalaDoctor* doc = getNextDoc())
            {
                doc->diagnose(koala);
                if (KoalaNurse* nurse = getNextNurse())
                {
                    std::string drug = nurse->readReport(koala->getName() + ".report");
                    nurse->giveDrug(drug, koala);
                }
            }
        SickKoalaList* toDelete = _currSick;
        _currSick = _currSick->getNext();
        _sickList->remove(toDelete);
    }
    for (_currNurse = _nurseList; _currNurse != NULL;)
    {
        if (KoalaNurse* nurse = _currNurse->getContent())
            nurse->timeCheck();
        KoalaNurseList* toDelete = _currNurse;
        _currNurse = _currNurse->getNext();
        _nurseList->remove(toDelete);
    }
    for (_currDoc = _doctorList; _currDoc != NULL;)
    {
        if (KoalaDoctor* doc = _currDoc->getContent())
            doc->timeCheck();
        KoalaDoctorList* toDelete = _currDoc;
        _currDoc = _currDoc->getNext();
        _doctorList->remove(toDelete);
    }
}

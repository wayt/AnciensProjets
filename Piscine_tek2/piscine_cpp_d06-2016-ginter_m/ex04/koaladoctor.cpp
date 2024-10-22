/*
** koaladoctor.cpp for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 14:51:25 2013 maxime ginters
** Last update Mon Jan 14 14:51:25 2013 maxime ginters
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "koaladoctor.h"

KoalaDoctor::KoalaDoctor(std::string name) : _name(name), _working(false)
{
    std::cout << "Dr." << _name << ": Je suis le Dr." << _name << " ! Comment Kreoggez-vous ?" << std::endl;
}

KoalaDoctor::~KoalaDoctor() {}

void KoalaDoctor::diagnose(SickKoala* koala)
{
    if (!koala)
        return;
    std::cout << "Dr." << _name << ": Alors, qu'est-ce qui vous goerk, Mr." << koala->getName() << " ?" << std::endl;
    koala->poke();

    std::string drug;
    switch (random() % 5)
    {
        case 0:
            drug = "mars";
            break;
        case 1:
            drug = "Buronzand";
            break;
        case 2:
            drug = "Viagra";
            break;
        case 3:
            drug = "Extasy";
            break;
        case 4:
            drug = "Feuille d'eucalyptus";
            break;
    }

    std::ofstream file;
    std::ios_base::openmode openmode = std::ios_base::out | std::ios_base::trunc;
    std::string filename = koala->getName() + ".report";
    file.open(filename.c_str(), openmode);
    if (file.is_open())
    {
        file << drug << std::endl;
        file.close();
    }
}

void KoalaDoctor::timeCheck()
{
    if (_working)
        std::cout << "Dr." << _name << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
    else
        std::cout << "Dr." << _name << ": Je commence le travail !" << std::endl;
    _working = !_working;

}

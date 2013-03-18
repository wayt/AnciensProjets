/*
** Exam.cpp for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 17:12:56 2013 maxime ginters
** Last update Tue Jan 15 17:12:56 2013 maxime ginters
*/

#include <iostream>
#include "Exam.hh"

bool Exam::cheat = false;

Exam::Exam(bool* c)
{
    Exam::cheat = *c;
}

bool Exam::isCheating()
{
    return Exam::cheat;
}

void Exam::start(int eger)
{
    std::cout << "[The exam is starting]" << std::endl;
    std::cout << eger << " Klingon vessels appeared out of nowhere." << std::endl;
    std::cout << "they are fully armed and shielded" << std::endl;
    if (Exam::cheat)
        std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
    else
        std::cout << "This exam is hard... you lost again." << std::endl;
}

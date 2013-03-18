/*
** Squad.h for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07a-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 16 02:32:49 2013 maxime ginters
** Last update Wed Jan 16 02:47:01 2013 maxime ginters
*/

#ifndef SQUAD_H_
# define SQUAD_H_

#include "Sounds.h"

const std::string Sounds::Regular = "Bang";
const std::string Sounds::Plasma = "Fwooosh";
const std::string Sounds::Rocket = "Boouuuuuum";

class Squad
{
public:
    Squad(int posXBegin, int posYBegin, Phaser::AmmoType ammoType,
            int size = 5);
    ~Squad();

public:
    void fire();
    void localisation();

public:
    [...] skats();
    Skat* at(int idx) const;
    int size();
private:
    int _size;
};

#endif /* !SQUAD_H_ */

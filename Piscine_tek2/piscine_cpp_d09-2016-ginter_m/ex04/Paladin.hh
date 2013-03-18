/*
 ** Paladin.hh for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d09-2016-ginter_m/ex03
 **
 ** Made by maxime ginters
 ** Login  <ginter_m@epitech.eu>
 **
 ** Started on  Thu Jan 17 16:58:55 2013 maxime ginters
 ** Last update Thu Jan 17 17:31:17 2013 maxime ginters
 */

#ifndef PALADIN_H_
# define PALADIN_H_

#include <string>
#include "Warrior.hh"
#include "Priest.hh"

class Paladin : public Warrior, public Priest
{
    public:
        explicit Paladin(std::string const& name, int level);

        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        int Intercept();
};

#endif /* !PALADIN_H_ */

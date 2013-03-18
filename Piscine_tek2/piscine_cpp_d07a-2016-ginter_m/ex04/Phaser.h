/*
** Phaser.h for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07a-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 16 00:48:12 2013 maxime ginters
** Last update Wed Jan 16 02:09:50 2013 maxime ginters
*/

#ifndef PHASER_H_
# define PHASER_H_

#include "Sounds.h"

class Phaser
{
public:
    enum AmmoType
    {
        REGULAR     = 0,
        PLASMA,
        ROCKET,
    };

    Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
    ~Phaser();

    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);

    int getCurrentAmmos() const;

private:
    static const int Empty = 0;
    const int _maxAmmo;
    int _currentAmmo[3];
    AmmoType _type;

};

#endif /* !PHASER_H_ */

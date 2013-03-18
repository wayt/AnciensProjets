/*
** Cesar.h for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d17-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 25 12:20:21 2013 maxime ginters
** Last update Fri Jan 25 13:39:36 2013 maxime ginters
*/

#ifndef CESAR_H_
# define CESAR_H_

#include <iostream>
#include "IEncryptionMethod.h"

class Cesar : public IEncryptionMethod
{
public:
    Cesar();
    virtual ~Cesar();

    void encryptChar(char plainchar);
    void decryptChar(char cipherchar);
    void reset();
private:
    int _shift;
};

#endif /* !CESAR_H_ */

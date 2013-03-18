/*
** Cesar.cpp for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d17-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 25 12:34:57 2013 maxime ginters
** Last update Fri Jan 25 13:56:18 2013 maxime ginters
*/

#include "Cesar.h"

char truc_bizarre(char v)
{
    return (v < 0 ? -(26 + v) : v);
}

Cesar::Cesar() :
    _shift(3)
{}

Cesar::~Cesar()
{}

void Cesar::encryptChar(char plainchar)
{
    if (plainchar >= 'a' && plainchar <= 'z')
        plainchar = 'a' + ((plainchar - 'a' + _shift) % 26);
    else if (plainchar >= 'A' && plainchar <= 'Z')
        plainchar = 'A' + ((plainchar - 'A' + _shift) % 26);
    std::cout << plainchar;
    ++_shift;
}

void Cesar::decryptChar(char cipherchar)
{
    if (cipherchar >= 'a' && cipherchar <= 'z')
    {
        cipherchar = (cipherchar - 'a' - _shift) % 26;
        if (cipherchar < 0)
            cipherchar += 26;
        cipherchar += 'a';
    }
    else if (cipherchar >= 'A' && cipherchar <= 'Z')
    {
        cipherchar = (cipherchar - 'A' - _shift) % 26;
        if (cipherchar < 0)
            cipherchar += 26;
        cipherchar += 'A';
    }
    std::cout << cipherchar;
    ++_shift;
}

void Cesar::reset()
{
    _shift = 3;
}

/*
** main.cpp for ex02 in /home/leroy_v/Epitech/projet_tek2/piscine/Jour_17/ex02
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Fri Jan 25 10:59:02 2013 vincent leroy
** Last update Fri Jan 25 11:35:59 2013 vincent leroy
*/

#include <iostream>
#include <string>
#include "Cesar.h"

static void encryptString(IEncryptionMethod& encryptionMethod, std::string const& toEncrypt)
{
    size_t len = toEncrypt.size();

    encryptionMethod.reset();
    for (size_t i = 0; i < len; ++i)
    {
        encryptionMethod.encryptChar(toEncrypt[i]);
    }
    std::cout << std::endl;
}

static void decryptString(IEncryptionMethod& encryptionMethod, std::string const& toDecrypt)
{
    size_t len = toDecrypt.size();

    encryptionMethod.reset();
    for (size_t i = 0; i < len; ++i)
    {
        encryptionMethod.decryptChar(toDecrypt[i]);
    }
    std::cout << std::endl;
}

int main()
{
    Cesar c;

    encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
    decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !");
    encryptString(c, "KIKOO");
    encryptString(c, "LULZ XD");
    decryptString(c, "Ziqivun ea Ndcsg.Wji !");
    return 0;
}

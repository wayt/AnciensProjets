/*
** sickkoala.cpp for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 11:20:09 2013 maxime ginters
** Last update Mon Jan 14 11:20:09 2013 maxime ginters
*/

#include <cctype>
#include <algorithm>
#include "sickkoala.h"

SickKoala::SickKoala(std::string name) : _name(name)
{
    
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << _name << ": Kreooogg !! Je suis gueriiii !" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << _name << ": Gooeeeeerrk !! :'(" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug == "Buronzand")
    {
        std::cout << "Mr." << _name << ": Et la fatigue a fait son temps !" << std::endl;
        return true;
    }
    std::transform(drug.begin(), drug.end(), drug.begin(), ::toupper);
    if (drug == "MARS")
    {
        std::cout << "Mr." << _name << ": Mars, et ca Kreog !" << std::endl;
        return true;
    }
    std::cout << "Mr." << _name << ": Goerk !" << std::endl;
    return false;
}
    
void SickKoala::overDrive(std::string str)
{
    size_t pos;
    std::string rp_str = "Kreog !";
    do
    {
        pos = str.find(rp_str);
        if (pos != std::string::npos)
            str.replace(pos, rp_str.length(), "1337 !");
    } while (pos != std::string::npos);

    std::cout << "Mr." << _name << ": " << str << std::endl;
}

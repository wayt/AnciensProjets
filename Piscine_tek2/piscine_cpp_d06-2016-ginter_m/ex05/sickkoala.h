/*
** sickkoala.h for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 11:16:44 2013 maxime ginters
** Last update Mon Jan 14 14:49:00 2013 maxime ginters
*/

#ifndef SICKKOALA_H_
# define SICKKOALA_H_

#include <string>
#include <iostream>

class SickKoala
{
public:
    explicit SickKoala(std::string name);
    virtual ~SickKoala();

    void poke();
    bool takeDrug(std::string drug);
    void overDrive(std::string str);
    std::string getName();
private:
    std::string _name;
};

#endif /* !SICKKOALA_H_ */

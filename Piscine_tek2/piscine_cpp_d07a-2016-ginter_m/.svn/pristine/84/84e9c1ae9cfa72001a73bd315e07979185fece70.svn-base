/*
** Skat.h for piscine_cpp_d07a-2016-ginter_m in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07a-2016-ginter_m
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 18:15:20 2013 maxime ginters
** Last update Tue Jan 15 21:29:19 2013 maxime ginters
*/

#ifndef SKAT_H_
# define SKAT_H_

#include <string>

class Skat
{
public:
    Skat(std::string const& name = "bob", int stimPaks = 15);
    ~Skat();

    unsigned int& stimPaks();
    const std::string& name() const;

    void shareStimPaks(int number, unsigned int& stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();

    void status() const;

private:
    std::string _name;
    unsigned int _stimPaks;
};

#endif /* !SKAT_H_ */

/*
** Warpsystem.hh for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 09:52:31 2013 maxime ginters
** Last update Tue Jan 15 10:37:38 2013 maxime ginters
*/

#ifndef WARPSYSTEM_H_
# define WARPSYSTEM_H_

namespace WarpSystem
{

class QuantumReactor
{
public:
    explicit QuantumReactor();
    virtual ~QuantumReactor() {}

    bool isStable();
    void setStability(bool stable);
private:
    bool _stability;
};

class Core
{
public:
    explicit Core(QuantumReactor* reactor);
    virtual ~Core() {}

    QuantumReactor* getReactor();
private:
    QuantumReactor* _coreReactor;
};

}

#endif /* !WARPSYSTEM_H_ */

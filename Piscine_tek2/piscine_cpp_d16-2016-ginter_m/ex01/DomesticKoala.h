/*
** DomesticKoala.h for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 13:25:50 2013 maxime ginters
** Last update Thu Jan 24 14:09:22 2013 maxime ginters
*/

#ifndef DOMESTICKOALA_H_
# define DOMESTICKOALA_H_

#include <string>
#include <vector>
#include "KoalaAction.h"

class DomesticKoala
{
public:
    explicit DomesticKoala(KoalaAction& action);
    virtual ~DomesticKoala();
    explicit DomesticKoala(DomesticKoala const& other);
    DomesticKoala& operator=(DomesticKoala const& other);

    typedef void (KoalaAction::*methodPointer_t)(std::string const&);
    std::vector<methodPointer_t> const* getActions() const;
    void learnAction(unsigned char c, methodPointer_t ptr);
    void unlearnAction(unsigned char c);
    void doAction(unsigned char, std::string const& str);
    void setKoalaAction(KoalaAction& action);
private:
    KoalaAction _action;
    std::vector<methodPointer_t> _knowAction;
};

#endif /* !DOMESTICKOALA_H_ */

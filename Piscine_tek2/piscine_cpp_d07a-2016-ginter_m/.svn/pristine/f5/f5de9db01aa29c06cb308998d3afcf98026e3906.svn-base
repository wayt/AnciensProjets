/*
** KoalaBot.h for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07a-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 21:57:01 2013 maxime ginters
** Last update Tue Jan 15 22:28:37 2013 maxime ginters
*/

#ifndef KOALABOT_H_
# define KOALABOT_H_

#include <string>
#include "Parts.h"

class KoalaBot
{
public:
    explicit KoalaBot(std::string const& serial = "Bob-01");
    virtual ~KoalaBot() {}

    void setParts(Arms const& arms);
    void setParts(Legs const& legs);
    void setParts(Head const& head);
    void swapParts(Arms& arms);
    void swapParts(Legs& legs);
    void swapParts(Head& head);

    void informations() const;
    bool status() const;
private:
    std::string _serial;
    Arms _arms;
    Legs _legs;
    Head _head;
};

#endif /* !KOALABOT_H_ */

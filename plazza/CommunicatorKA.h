/*
** CommunicatorKA.h for namedPipe in /home/leroy_v/Epitech/projet_tek2/namedPipe
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Tue Apr 16 16:15:11 2013 vincent leroy
** Last update Fri Apr 19 19:06:31 2013 maxime ginters
*/

#ifndef COMMUNICATORKA_H_
# define COMMUNICATORKA_H_

#include <string>
#include "Stream.h"

class CommunicatorKA
{
    public:
        explicit CommunicatorKA(int id);
        virtual ~CommunicatorKA();

        bool send(const std::string &msg) const;
        std::string recv() const;

        CommunicatorKA const& operator<<(std::string const& msg) const;
        CommunicatorKA const& operator>>(std::string& msg) const;

    private:
        std::string _pipeName;
        Stream _fdIn;
        Stream _fdOut;
};

#endif /* !COMMUNICATORKA_H_ */

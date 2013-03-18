/*
** SMTP.h for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 10:03:03 2013 vincent leroy
** Last update Sun Mar 10 09:40:13 2013 vincent leroy
*/

#ifndef SMTP_H_
# define SMTP_H_

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <QDate>
#include <QString>
#include "ASocket.h"
#include "Exception.hpp"

namespace Protocol
{

class SMTP : public ASocket
{
    public:
        explicit SMTP();
        virtual ~SMTP();

        bool login(const std::string &, const std::string &) const;
        bool sendMsg(const std::string&, const std::string&, const std::string&, const std::string&);
};

}

#endif /* !SMTP_H_ */

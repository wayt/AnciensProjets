/*
** AReceveur.h for rush-mars-2016-leroy_v in /home/leroy_v/Epitech/projet_tek2/rush-mars-2016-leroy_v
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sun Mar 10 06:49:29 2013 vincent leroy
** Last update Sun Mar 10 11:11:42 2013 vincent leroy
*/

#ifndef ARECEVEUR_H_
# define ARECEVEUR_H_

#include <string>
#include <list>
#include <vector>
#include "ASocket.h"

namespace Protocol
{

class AReceveur : public ASocket
{
    public:
        explicit AReceveur();
        virtual ~AReceveur();

        virtual std::list<std::string> getFolders() const = 0;
        virtual std::list<std::vector<std::string> > getMails(const std::string &) const = 0;
        virtual std::string getMail(const std::string &) const = 0;
        virtual void removeMail(const std::string&) const = 0;
};

}

#endif /* !ARECEVEUR_H_ */

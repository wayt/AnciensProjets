/*
** IMAP.h for bmail in /home/vaga/Projects/tek2/bmail
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sat Mar 09 10:50:18 2013 fabien casters
** Last update Sun Mar 10 11:32:22 2013 vincent leroy
*/

#ifndef IMAP_H_
# define IMAP_H_

#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include "AReceveur.h"

namespace Protocol
{

class IMAP : public AReceveur
{
    public:
        IMAP();
        virtual ~IMAP() {}
        bool login(const std::string &, const std::string &) const;
        std::list<std::string> getFolders() const;
        std::list<std::vector<std::string> > getMails(const std::string &) const;
        std::string getMail(const std::string &) const;
        void removeMail(const std::string&) const;
};

}

#endif


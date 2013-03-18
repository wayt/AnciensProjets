/*
** IMAP.cpp for bmail in /home/vaga/Projects/tek2/bmail
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sat Mar 09 10:52:28 2013 fabien casters
** Last update Sun Mar 10 14:36:13 2013 fabien casters
*/

#include "IMAP.h"
#include "Exception.hpp"

namespace Protocol
{

IMAP::IMAP() : AReceveur()
{
}

bool IMAP::login(const std::string &user, const std::string &password) const
{
    std::string result = sendAndReceive("LGN login " + user + " " + password + "\n");

    return (result.find("LGN OK ") != std::string::npos);
}

std::list<std::string> IMAP::getFolders() const
{
    std::list<std::string> folders;
    std::string result = sendAndReceive("FLD list \"\" \"*\"\n");

    std::stringstream ss(result);
    std::string line;
    size_t pos;
    while (getline(ss, line))
    {
        if ((pos = line.rfind("\"/\" ")) != std::string::npos)
        {
            line = line.substr(pos + 4);
            for (size_t i = 0; i < line.size(); ++i)
                if (line[i] == '"' || line[i] == '\r' || line[i] == '\n')
                {
                    line.erase(i, 1);
                    --i;
                }
            folders.push_front(line);
        }
    }

    return folders;
}


std::list<std::vector<std::string> > IMAP::getMails(const std::string &folder) const
{
    std::list<std::vector<std::string> > mails;
    std::string cmd = "MLS1 select " + folder + "\n";
    sendAndReceive(cmd);
    std::string result = sendAndReceive("MLS2 fetch 1:* (UID BODY.PEEK[HEADER.FIELDS (Subject)] BODY.PEEK[HEADER.FIELDS (Date)])\n");
    unsigned int total = result.length();
    for(unsigned int i = 0; i < total; i++)
    {
        if (result[i] == '*')
            result[i] = '\n';
        else if (result[i] == '\r')
            result[i] = ' ';
        else if (result[i] == '\n')
            result[i] = ' ';
    }
    std::stringstream ss(result);
    std::string line;
    size_t start;
    size_t end;
    while(std::getline(ss, line))
    {
        if ((start = line.find("UID ")) != std::string::npos)
        {
            std::vector<std::string> vec;
            end = line.find(" BODY");
            vec.push_back(line.substr(start + 4, end - start - 4));
            start = line.find("Subject: ");
            end = line.find("    BODY");
            vec.push_back(line.substr(start + 9, end - start - 9));
            start = line.find("Date: ");
            end = (line.find(" )  MLS2") == std::string::npos) ? line.length() - 3 : line.find(" )  MLS2") ;
            vec.push_back(line.substr(start + 6, end - start - 7));
            mails.push_front(vec);
        }
    }
    return mails;
}

std::string IMAP::getMail(const std::string &id) const
{
    std::string result = sendAndReceive("ML1 uid fetch " + id + " BODY[TEXT]\n");

    size_t start = result.find("}");
    size_t end = result.find("ML1");
    return result.substr(start + 1, end - start - 4);
}

void IMAP::removeMail(const std::string &uid) const
{
    sendAndReceive("DLT1 store " + uid + " flags \\Deleted\n");
    sendAndReceive("DLT2 expunge\n");

}

}


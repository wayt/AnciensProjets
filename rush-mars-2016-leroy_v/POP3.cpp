/*
** POP3.cpp for rush-mars-2016-leroy_v in /home/leroy_v/Epitech/projet_tek2/bmail/rush-mars-2016-leroy_v
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 17:19:14 2013 vincent leroy
** Last update Sun Mar 10 14:36:14 2013 fabien casters
*/

#include "POP3.h"
#include "Exception.hpp"

namespace Protocol
{

POP3::POP3() : AReceveur()
{
}

POP3::~POP3()
{
}

bool POP3::login(const std::string &user, const std::string &pass) const
{
    std::string cmd("USER ");

    cmd += user + "\r\n";
    std::cout << sendAndReceive("USER " + user + "\r\n") << std::endl;
    cmd = "PASS " + pass + "\r\n";
    std::string result = sendAndReceive(cmd);

    std::cout << result << std::endl;
    if (result.find("+OK") != std::string::npos)
        return true;

    return false;
}

std::list<std::string> POP3::getFolders() const
{
    std::list<std::string> folders;

    folders.push_front("INBOX");
    return folders;
}

std::string POP3::getHeader(const std::string &key, const std::string &content) const
{
    size_t start = content.find(key);
    if (start == std::string::npos)
        return "";
    size_t end = content.find("\r\n", start);
    return content.substr(start + key.length(), end - start - key.length());
}

std::list<std::vector<std::string> > POP3::getMails(const std::string &) const
{
    std::list<std::vector<std::string> > mails;
    std::string result = sendAndReceive("STAT\r\n");
    std::stringstream ss(result);
    std::string total;
    int t;
    ss >> total >> t;
    for (int i = 1; i <= t; ++i)
    {
        std::vector<std::string> vec;
        std::stringstream ss2;
        ss2 << i;
        std::string result2 = sendAndReceive("RETR " + ss2.str() + "\r\n");
        if (result2.find("+OK") != std::string::npos)
        {
            vec.push_back(ss2.str());
            vec.push_back(getHeader("Subject: ", result2));
            vec.push_back(getHeader("Date: ", result2));
            mails.push_front(vec);
        }
    }
    return mails;
}

std::string POP3::getMail(const std::string &num) const
{
    std::string result = sendAndReceive("RETR " + num + "\r\n");
    size_t start = result.find("\r\n\r\n");
    size_t end = result.find("\r\n.\r\n", start);
    return result.substr(start + 4, end - start - 4);
}

void POP3::removeMail(const std::string &uid) const
{
    std::string res = sendAndReceive("DELE " + uid + "\r\n");
}

}

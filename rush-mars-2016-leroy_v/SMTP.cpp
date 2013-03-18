/*
** SMTP.cpp for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 10:03:00 2013 vincent leroy
** Last update Sun Mar 10 09:43:36 2013 vincent leroy
*/

#include "SMTP.h"

namespace Protocol
{

SMTP::SMTP() :
    ASocket()
{
    if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        throw Exception::ExceptSocket();
}

SMTP::~SMTP()
{
    close(_socket);
}

bool SMTP::login(const std::string &user, const std::string &mdp) const
{
    std::string result = sendAndReceive("auth login\r\n");
    result = sendAndReceive(user + "\r\n");
    result = sendAndReceive(mdp + "\r\n");
    return (result.find("235") != std::string::npos);
}

bool SMTP::sendMsg(const std::string &to, const std::string &from, const std::string &subject, const std::string &text)
{
    std::string result = sendAndReceive("mail from: <" + from + ">\r\n");
    if (result.find("250") == std::string::npos)
        return false;
    result = sendAndReceive("rcpt to: <" + to + ">\r\n");
    if (result.find("250") == std::string::npos)
        return false;
    result = sendAndReceive("data\r\n");
    result = sendAndReceive("From: " + from + "\r\nTo: " + to + "\r\nSubject: " + subject + "\r\nDate: " + std::string(qPrintable((QDate::currentDate().toString()))) + "\r\n\r\n" + text + "\r\n.\r\n");
    return (result.find("250") != std::string::npos);
}

}

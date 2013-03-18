/*
** Setting.cpp for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 11:15:34 2013 vincent leroy
** Last update Sun Mar 10 07:52:44 2013 vincent leroy
*/

#include "Setting.h"

Setting::Setting() :
    _setting(QSettings::IniFormat, QSettings::UserScope, "bmail")
{
}

Setting::~Setting()
{
}

QString Setting::getIpReceveur() const
{
    return _setting.value("RECEVEUR/ip").toString();
}

int Setting::getPortReceveur() const
{
    return _setting.value("RECEVEUR/port").toInt();
}

QString Setting::getProtocol() const
{
    return _setting.value("RECEVEUR/protocol").toString();
}

QString Setting::getIpSender() const
{
    return _setting.value("SENDER/ip").toString();
}

int Setting::getPortSender() const
{
    return _setting.value("SENDER/port").toInt();
}

QString Setting::getLogin() const
{
    return _setting.value("USER/login").toString();
}

QString Setting::getMdp() const
{
    return _setting.value("USER/mdp").toString();
}

void Setting::setReceveur(const QString &ip, int port, const QString &proto)
{
    _setting.beginGroup("RECEVEUR");
    _addInfo(ip, port);
    _setting.setValue("protocol", proto);
    _setting.endGroup();
}

void Setting::setSender(const QString &ip, int port)
{
    _setting.beginGroup("SENDER");
    _addInfo(ip, port);
    _setting.endGroup();
}

void Setting::setUser(const QString &login, const QString &mdp)
{
    _setting.beginGroup("USER");
    _setting.setValue("login", login);
    _setting.setValue("mdp", mdp);
    _setting.endGroup();
}

void Setting::_addInfo(const QString &ip, int port)
{
    _setting.setValue("ip", ip);
    _setting.setValue("port", port);
}

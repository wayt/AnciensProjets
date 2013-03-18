/*
** KoalaAction.cpp for ex01 in /home/leroy_v/Epitech/projet_tek2/piscine/Jour_16/ex01
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Thu Jan 24 12:19:49 2013 vincent leroy
** Last update Thu Jan 24 12:25:27 2013 vincent leroy
*/

#include "KoalaAction.h"

KoalaAction::KoalaAction()
{
}

KoalaAction::~KoalaAction()
{
}

void KoalaAction::eat(const std::string &str)
{
    std::cout << "I eat: " << str << std::endl;
}

void KoalaAction::sleep(const std::string &str)
{
    std::cout << "I sleep: " << str << std::endl;
}

void KoalaAction::goTo(const std::string &str)
{
    std::cout << "I go to: " << str << std::endl;
}

void KoalaAction::reproduce(const std::string &str)
{
    std::cout << "I reproduce: " << str << std::endl;
}

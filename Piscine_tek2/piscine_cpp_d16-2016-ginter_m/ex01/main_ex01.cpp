/*
** main.cpp for ex01 in /home/leroy_v/Epitech/projet_tek2/piscine/Jour_16/ex01
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Thu Jan 24 12:51:45 2013 vincent leroy
** Last update Thu Jan 24 14:12:44 2013 maxime ginters
*/

#include <iostream>
#include <string>
#include "DomesticKoala.h"
#include "KoalaAction.h"

int main()
{
    KoalaAction action;
    DomesticKoala *dk = new DomesticKoala(action);
    dk->learnAction('<', &KoalaAction::eat);
    dk->learnAction('>', &KoalaAction::goTo);
    dk->learnAction('#', &KoalaAction::sleep);
    dk->learnAction('X', &KoalaAction::reproduce);

    //dk->unlearnAction('X');

    dk->doAction('>', "{Epitech.}");
    dk->doAction('<', "a DoubleCheese");
    dk->doAction('X', "a Seagull");
    dk->doAction('#', "The end of the C++ pool, and an Astek burning on a stake");

    delete dk;

    return 0;
}

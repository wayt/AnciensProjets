/*
** ModuleCoreQT.h for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 14:39:41 2013 fabien casters
** Last update Wed Jan 30 01:40:18 2013 vincent leroy
*/

#ifndef MODULECOREQT_H_
# define MODULECOREQT_H_

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include "AModuleCore.h"

class ModuleCoreQT : public AModuleCore
{
public:
    ModuleCoreQT();
    virtual ~ModuleCoreQT();

    void init();
    void display();

private:
    QApplication *_app;
    QWidget *_main;
    QGridLayout *_layout;
};

#endif

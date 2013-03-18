/*
** QTText.cpp for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 12:07:20 2013 fabien casters
** Last update Wed Jan 30 01:29:02 2013 vincent leroy
*/

#include "QTText.h"

QTText::QTText() : _label(NULL)
{
}

QTText::~QTText()
{
}

QWidget* QTText::init(QWidget *parent)
{
    _label = new QLabel(parent);
    _label->show();

    return _label;
}

void QTText::display()
{
    _label->setText(_values.front().c_str());
    _label->resize(_label->sizeHint());
}

/*
** QTText.h for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 11:56:47 2013 fabien casters
** Last update Wed Jan 30 02:47:22 2013 fabien casters
*/

#ifndef QTTEXT_H_
# define QTTEXT_H_

#include <QLabel>
#include "AMonitorDisplay.h"

class QTText : public AMonitorDisplay
{
public:
    QTText();
    virtual ~QTText();

    void init(WINDOW*, int, int) {}
    QWidget* init(QWidget *);
    void display();

private:
    QLabel *_label;
};

#endif

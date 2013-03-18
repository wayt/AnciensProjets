/*
** QTBarre.h for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 12:03:36 2013 fabien casters
** Last update Wed Jan 30 02:47:46 2013 fabien casters
*/

#ifndef QTBARRE_H_
# define QTBARRE_H_

#include "AMonitorDisplay.h"

class QTBarre : public AMonitorDisplay
{
public:
    QTBarre();
    virtual ~QTBarre();

    void init(WINDOW*, int, int) {}
    QWidget* init(QWidget *);
    void display();

private:
};

#endif

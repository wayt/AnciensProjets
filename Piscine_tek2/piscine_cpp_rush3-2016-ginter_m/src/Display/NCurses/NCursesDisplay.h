/*
** NCursesDisplay.h for src in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 11:56:50 2013 maxime ginters
** Last update Wed Jan 30 02:44:24 2013 fabien casters
*/

#ifndef NCURSESDISPLAY_H_
# define NCURSESDISPLAY_H_

#include <curses.h>
#include "AMonitorDisplay.h"

class NCursesDisplay : public AMonitorDisplay
{
public:
    NCursesDisplay() {}
    virtual ~NCursesDisplay() {}
    void init(WINDOW*, int, int);
    QWidget* init(QWidget*) { return NULL; }
protected:
    WINDOW* _window;
};

#endif /* !NCURSESDISPLAY_H_ */

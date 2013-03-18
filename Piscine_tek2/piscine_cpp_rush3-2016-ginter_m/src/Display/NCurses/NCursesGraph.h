/*
** NCursesGraph.h for src in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 11:57:53 2013 maxime ginters
** Last update Tue Jan 29 12:00:24 2013 maxime ginters
*/

#ifndef NCURSESGRAPH_H_
# define NCURSESGRAPH_H_

#include "NCursesDisplay.h"

class NCursesGraph : public NCursesDisplay
{
public:
    NCursesGraph() : NCursesDisplay() {}
    virtual ~NCursesGraph() {}

    void display() {}
};

#endif /* !NCURSESGRAPH_H_ */

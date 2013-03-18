/*
** NCursesBarre.cpp for  in /home/vaga/Projects/tek2/piscine/rush3/src/Display/NCurses
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 21:37:42 2013 fabien casters
** Last update Wed Jan 30 03:16:02 2013 vincent leroy
*/

#include "Utils.h"
#include "NCursesBarre.h"

/*
 * 50 - 2 max
 * ?      val
 */
void NCursesBarre::display()
{
    int width = 50 - 2;
    int max = to_int(_max.c_str());
    int val = to_int(_values.back().c_str());
    int i = 1;
    if (max == 0)
        max = 1;
    val = ((width) * val) / max;
    while ( i <= width)
    {
        if ( i <= val)
        {
            if (i < width / 2)
            {
                wattron(_window, COLOR_PAIR(1));
                mvwaddstr(_window, 1, i, "|");
                wattroff(_window, COLOR_PAIR(1));
            }
            else
            {
                wattron(_window, COLOR_PAIR(2));
                mvwaddstr(_window, 1, i, "|");
                wattroff(_window, COLOR_PAIR(2));
            }
        }
        else
            mvwaddstr(_window, 1, i, " ");
        i++;
    }
    mvwaddstr(_window, 2, 1, _values.back().c_str());
    mvwaddstr(_window, 2, 1 + _values.back().length(), "/");
    mvwaddstr(_window, 2, 2 + _values.back().length(), _max.c_str());
    mvwaddstr(_window, 2, 2 + _values.back().length() + _max.length(), _unite.c_str());
    mvwaddstr(_window, 2, 2 + _values.back().length() + _max.length() + _unite.length(), "        ");
    ::wrefresh(_window);
}

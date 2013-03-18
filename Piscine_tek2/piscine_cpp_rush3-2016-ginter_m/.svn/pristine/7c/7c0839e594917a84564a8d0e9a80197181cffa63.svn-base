/*
** AMonitorDisplay.h for  in /home/vaga/Projects/tek2/piscine/rush3/src
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Tue Jan 29 10:46:52 2013 fabien casters
** Last update Wed Jan 30 02:41:39 2013 fabien casters
*/

#ifndef AMONITORDISPLAY_H_
# define AMONITORDISPLAY_H_

#include <queue>
#include <string>
#include "IMonitorDisplay.h"

#define MAX_VALUE 10

class AMonitorDisplay : public IMonitorDisplay
{
public:
    AMonitorDisplay();
    virtual ~AMonitorDisplay() {}

    void addValue(std::string const&);
    void setMax(std::string const&);
    std::string const& getUnite() const;
    void setUnite(std::string const& unite);

protected:
    std::queue<std::string> _values;
    std::string _max;
    std::string _unite;
};

#endif

/*
** IMonitorModule.h for src in /home/fest/Epitech/Piscine_tek2/MyGKrellM/src
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 29 00:38:34 2013 maxime ginters
** Last update Wed Jan 30 01:07:15 2013 maxime ginters
*/

#ifndef IMONITORMODULE_H_
# define IMONITORMODULE_H_

#include <queue>
#include <string>
#include "IMonitorDisplay.h"

class IMonitorModule
{
public:
    virtual ~IMonitorModule() {}
    virtual void refresh() = 0;
    virtual std::string const& getName() const = 0;
    virtual void display() = 0;
    virtual IMonitorDisplay* getDisplay() = 0;
    virtual std::string const& getUnite() const = 0;
    virtual void setUnite(std::string const&) = 0;
};

#endif /* !IMONITORMODULE_H_ */

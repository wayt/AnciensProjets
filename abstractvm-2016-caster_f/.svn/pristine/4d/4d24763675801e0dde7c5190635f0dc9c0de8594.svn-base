/*
** VMParser.h abstractVM in /home/vaga/Projects/tek2/abstractVM
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Feb 15 12:47:05 2013 fabien casters
** Last update Wed Feb 20 15:22:23 2013 fabien casters
*/

#ifndef VMPARSER_H_
# define VMPARSER_H_

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#include "Exception.h"

class VMParser
{
 private:
    std::vector<std::string> _lines;
    std::string _path;
    static char _cleanLine(char);
 public:
    VMParser();
    virtual ~VMParser();

    void setPath(std::string const& path);
    std::vector<std::string> const &getLines();

    void addLinesFromFile(std::string const& path);
    void addLinesFromIO();
    void addLine(const std::string &);

    void exec();
};

#endif


/*
** VMCore.h for abstractVM in /home/vaga/Projects/tek2/abstractVM
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Feb 15 16:32:01 2013 fabien casters
** Last update Fri Feb 22 12:56:13 2013 fabien casters
*/

#ifndef VMCORE_H_
# define VMCORE_H_

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include "SharedDefines.h"

#include "VMParser.h"
#include "AOperand.h"
#include "OperandFactory.h"
#include "Exception.h"

class VMCore;
typedef int (VMCore::*pCommand)(const std::string &, const std::string &);

class VMCore
{
 private:
    VMParser _parser;
    std::map<std::string, pCommand> _commands;
    std::list<IOperand *> _operands;
    bool _verbose;
    int _currentLine;

    int pushAction(const std::string &, const std::string &);
    int popAction(const std::string &, const std::string &);
    int dumpAction(const std::string &, const std::string &);
    int assertAction(const std::string &, const std::string &);
    int addAction(const std::string &, const std::string &);
    int subAction(const std::string &, const std::string &);
    int mulAction(const std::string &, const std::string &);
    int divAction(const std::string &, const std::string &);
    int modAction(const std::string &, const std::string &);
    int printAction(const std::string &, const std::string &);
    int exitAction(const std::string &, const std::string &);

    static void dump(const IOperand *);

 public:
    VMCore();
    virtual ~VMCore();

    void setPath(const std::string &);
    void setVerbose(bool);
    bool isVerbose();
    void exec();
};

#endif

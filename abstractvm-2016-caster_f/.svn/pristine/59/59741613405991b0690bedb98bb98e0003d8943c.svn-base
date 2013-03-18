/*
** VMCore.cpp for abstractVM in /home/vaga/Projects/tek2/abstractVM
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Feb 15 16:36:21 2013 fabien casters
** Last update Fri Feb 22 13:25:32 2013 fabien casters
*/

#include "VMCore.h"

VMCore::VMCore() : _parser(), _commands(), _operands(), _verbose(false), _currentLine(1)
{
    _commands["push"] = &VMCore::pushAction;
    _commands["pop"] = &VMCore::popAction;
    _commands["dump"] = &VMCore::dumpAction;
    _commands["assert"] = &VMCore::assertAction;
    _commands["add"] = &VMCore::addAction;
    _commands["sub"] = &VMCore::subAction;
    _commands["mul"] = &VMCore::mulAction;
    _commands["div"] = &VMCore::divAction;
    _commands["mod"] = &VMCore::modAction;
    _commands["print"] = &VMCore::printAction;
    _commands["exit"] = &VMCore::exitAction;
}

VMCore::~VMCore()
{
    std::list<IOperand *>::iterator it;
    for (it = _operands.begin(); it != _operands.end(); ++it)
    {
        delete *it;
    }
}

void VMCore::setPath(std::string const& path)
{
    _parser.setPath(path);
}

void VMCore::setVerbose(bool v)
{
    _verbose = v;
}

bool VMCore::isVerbose()
{
    return _verbose;
}

int VMCore::pushAction(const std::string &type, const std::string &value)
{
    IOperand *ope = sOperandFactory->createOperand(sOperandFactory->getType(type), value);
    _operands.push_front(ope);

    if (isVerbose())
        std::cout << "Push value " << ope->toString() << " on the fucking stack." << std::endl;

    return 0;
}

int VMCore::popAction(const std::string &, const std::string &)
{
    if (_operands.size() == 0)
        throw Exception::ExceptStack(_currentLine);

    IOperand *ope = _operands.front();
    _operands.pop_front();

    if (isVerbose())
        std::cout << "Pop value " << ope->toString() << " on the fucking stack." << std::endl;

    delete ope;

    return 0;
}

void VMCore::dump(const IOperand *ope)
{
    std::cout << ope->toString() << std::endl;
}

int VMCore::dumpAction(const std::string &, const std::string &)
{
    std::for_each(_operands.begin(), _operands.end(), &VMCore::dump);
    return 0;
}

int VMCore::assertAction(const std::string &type, const std::string &value)
{
    if (_operands.size() == 0)
        throw Exception::ExceptStack(_currentLine);
    IOperand *ope = sOperandFactory->createOperand(sOperandFactory->getType(type), value);
    IOperand *ope2 = _operands.front();
    if ( !(*ope == *ope2) )
        throw Exception::ExceptAssert(_currentLine);
    delete ope;

    return 0;
}

int VMCore::addAction(const std::string &, const std::string &)
{
    if (_operands.size() < 2)
        throw Exception::ExceptStack(_currentLine);
    IOperand *nb2 = _operands.front();
    _operands.pop_front();
    IOperand *nb1 = _operands.front();
    _operands.pop_front();
    IOperand *result = *nb1 + *nb2;
    _operands.push_front(result);

    if (isVerbose())
        std::cout << nb1->toString() << " + " << nb2->toString() << " = " << result->toString() << std::endl;

    delete nb1;
    delete nb2;

    return 0;
}

int VMCore::subAction(const std::string &, const std::string &)
{
    if (_operands.size() < 2)
        throw Exception::ExceptStack(_currentLine);
    IOperand *nb2 = _operands.front();
    _operands.pop_front();
    IOperand *nb1 = _operands.front();
    _operands.pop_front();
    IOperand *result = *nb1 - *nb2;
    _operands.push_front(result);

    if (isVerbose())
        std::cout << nb1->toString() << " - " << nb2->toString() << " = " << result->toString() << std::endl;

    delete nb1;
    delete nb2;

    return 0;
}

int VMCore::mulAction(const std::string &, const std::string &)
{
    if (_operands.size() < 2)
        throw Exception::ExceptStack(_currentLine);
    IOperand *nb2 = _operands.front();
    _operands.pop_front();
    IOperand *nb1 = _operands.front();
    _operands.pop_front();
    IOperand *result = *nb1 * *nb2;
    _operands.push_front(result);

    if (isVerbose())
        std::cout << nb1->toString() << " * " << nb2->toString() << " = " << result->toString() << std::endl;

    delete nb1;
    delete nb2;

    return 0;
}

int VMCore::divAction(const std::string &, const std::string &)
{
    if (_operands.size() < 2)
        throw Exception::ExceptStack(_currentLine);
    IOperand *nb2 = _operands.front();
    _operands.pop_front();
    IOperand *nb1 = _operands.front();
    _operands.pop_front();
    IOperand *result = *nb1 / *nb2;
    _operands.push_front(result);

    if (isVerbose())
        std::cout << nb1->toString() << " / " << nb2->toString() << " = " << result->toString() << std::endl;

    delete nb1;
    delete nb2;

    return 0;
}

int VMCore::modAction(const std::string &, const std::string &)
{
    if (_operands.size() < 2)
        throw Exception::ExceptStack(_currentLine);
    IOperand *nb2 = _operands.front();
    _operands.pop_front();
    IOperand *nb1 = _operands.front();
    _operands.pop_front();
    IOperand *result = *nb1 % *nb2;
    _operands.push_front(result);

    if (isVerbose())
        std::cout << nb1->toString() << " % " << nb2->toString() << " = " << result->toString() << std::endl;

    delete nb1;
    delete nb2;

    return 0;
}

int VMCore::printAction(const std::string &, const std::string &)
{
    if (_operands.size() < 1)
        throw Exception::ExceptStack(_currentLine);
    IOperand *nb = _operands.front();
    if (nb->getType() != TYPE_INT8)
        throw Exception::ExceptNotInt8(_currentLine);
    int64 tmp = AOperand::toInt64(nb->toString());
    std::cout << (int8) tmp << std::endl;

    return 0;
}

int VMCore::exitAction(const std::string &, const std::string &)
{
    if (isVerbose())
        std::cout << "Exit." << std::endl;

    return 1;
}

void VMCore::exec()
{
    _parser.exec();
    std::vector<std::string>::const_iterator it;
    std::stringstream ss;
    std::string cmd;
    std::string param1;
    std::string param2;
    int end = 0;

    for (it = _parser.getLines().begin(); end == 0 && it != _parser.getLines().end(); it++)
    {
        ss.clear();
        ss.str(*it);
        cmd = "";
        param1 = "";
        param2 = "";
        ss >> cmd >> param1 >> param2;
        if (!cmd.empty())
        {
            if (_commands.find(cmd) != _commands.end())
                end = (this->*_commands[cmd])(param1, param2);
            else
                throw Exception::ExceptCommandNotFound(_currentLine);
        }
        _currentLine++;
    }
    if (end == 0)
        throw Exception::ExceptNoExit();
}

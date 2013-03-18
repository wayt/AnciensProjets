/*
** Parser.h for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 09:34:58 2013 maxime ginters
** Last update Thu Jan 24 11:07:31 2013 maxime ginters
*/

#ifndef PARSER_H_
# define PARSER_H_

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Parser
{
public:
    Parser();
    Parser(Parser const& other);
    virtual ~Parser();
    Parser& operator=(Parser const& other);

    void feed(std::string const& str);
    int result() const;
    void reset();
private:
    bool _isOperator(char c) const;
    void _reset_stack();
    void reverseStack(std::stack<std::string>& st) const;
    int _calc(std::stack<int>& st, std::string const& op) const;
    int _result;
    std::stack<char> _operator;
    std::stack<std::string> _operand;
};

#endif /* !PARSER_H_ */

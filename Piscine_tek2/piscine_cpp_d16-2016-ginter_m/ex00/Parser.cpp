/*
** Parser.cpp for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 09:43:45 2013 maxime ginters
** Last update Thu Jan 24 11:25:16 2013 maxime ginters
*/

#include "Parser.h"

Parser::Parser() :
    _result(0), _operator(), _operand()
{}

Parser::Parser(Parser const& other)
{
    _result = other._result;
    _operator = other._operator;
    _operand = other._operand;
}

Parser::~Parser()
{}

Parser& Parser::operator=(Parser const& other)
{
    _result = other._result;
    _operator = other._operator;
    _operand = other._operand;
    return *this;
}

void Parser::feed(std::string const& str_bad)
{
    std::stringstream ss;
    for (size_t i = 0; i < str_bad.length(); ++i)
        if (str_bad[i] != ' ')
            ss << str_bad[i];
    std::string str = ss.str();

    _reset_stack();
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (_isOperator(str[i]))
            _operator.push(str[i]);
        else if (str[i] == ')')
        {
            while (!_operator.empty())
            {
                char z[2];
                z[0] = _operator.top();
                _operator.pop();
                z[1] = 0;
                if (z[0] == '(')
                    break;
                _operand.push(z);
            }
        }
        else
        {
            const char* c = str.c_str();
            std::stringstream ss;
            ss << atoi(&c[i]);
            _operand.push(ss.str());
            while (i < str.length() && !_isOperator(c[i + 1]) && c[i + 1] != ')')
                ++i;
        }
    }
    while (!_operator.empty())
    {
        char z[2];
        z[0] = _operator.top();
        z[1] = 0;
        if (z[0] != '(')
            _operand.push(z);
        _operator.pop();
    }

    reverseStack(_operand);

    std::stack<int> nb;
    while (!_operand.empty())
    {
        std::string val = _operand.top();
        _operand.pop();
        if (_isOperator(val[0]))
            nb.push(_calc(nb, val));
        else
            nb.push(atoi(val.c_str()));
    }
    _result += nb.top();
}

int Parser::result() const
{
    return _result;
}

void Parser::reset()
{
    _result = 0;
}

bool Parser::_isOperator(char c) const
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(')
        return true;
    return false;
}

void Parser::_reset_stack()
{
    while (!_operator.empty())
        _operator.pop();
    while (!_operand.empty())
        _operand.pop();
}

void Parser::reverseStack(std::stack<std::string>& st) const
{
    std::stack<std::string> pouet;
    while (!st.empty())
    {
        pouet.push(st.top());
        st.pop();
    }
    st = pouet;
}

int Parser::_calc(std::stack<int>& st, std::string const& op) const
{
    int const v1 = st.top();
    st.pop();
    int const v2 = st.top();
    st.pop();
    switch (op[0])
    {
        case '+':
            return v2 + v1;
        case '-':
            return v2 - v1;
        case '*':
            return v2 * v1;
        case '/':
            return v2 / v1;
        case '%':
            return v2 % v1;
        default:
            return 0;
    }
    return 0;
}

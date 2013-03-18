/*
** ex06.hpp for ex06 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d15-2016-ginter_m/ex06
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 23 15:06:19 2013 maxime ginters
** Last update Wed Jan 23 15:33:58 2013 maxime ginters
*/

#ifndef EX06_H_
# define EX06_H_

#include <iostream>
#include <sstream>
#include <string>

template<class T>
std::string const type(T const& v)
{
    (void)v;
    return "[???]";
}

template<>
std::string const type<int>(int const& v)
{
    std::ostringstream ss;
    ss << "[int:";
    ss << v;
    ss << "]";
    return ss.str();
}

template<>
std::string const type<float>(float const& v)
{
    std::ostringstream ss;
    ss << "[float:";
    ss << v;
    ss << "f]";
    return ss.str();
}

template<>
std::string const type<std::string>(std::string const&  v)
{
    std::ostringstream ss;
    ss << "[string:\"";
    ss << v;
    ss << "\"]";
    return ss.str();
}

template<class T, class U = T>
class Tuple
{
public:
    T a;
    U b;
    std::string toString() const
    {
        std::ostringstream ss;
        ss << "[TUPLE ";
        ss << type(a);
        ss << " ";
        ss << type(b);
        ss << "]";
        return ss.str();
    }
};

#endif /* !EX06_H_ */

#include "Function.hpp"
#include <iostream>
#include <boost/bind.hpp>

int function(char c)
{
    std::cout << "CHAR: " << c << std::endl;
    return 0;
}

void secondfunction(char u, char actere)
{
    std::cout << "CHARU: " << u << " - CHARACTERE: " << actere << std::endl;
}

class callable
{
public:
    void operator()(std::string const& str) { std::cout << "---- " << str << std::endl; }

    void toto(char c)
    {
        std::cout << "CAjfalwjdlawkjdawlkjd " << c << std::endl;
    }
};

int quatreparams(char un, char deux, char trois, char quatre)
{
    std::cout << un << " - " << deux << " - " << trois << " - " << quatre << std::endl;
    return -42;
}

int main()
{
    Function<int(char)> f = &function;
    f('c');

    callable* call = new callable;
    Function<void(std::string const&)> h = *call;
    h("Coucou");

    Function<void(void)> obj = boost::bind(&callable::toto, call, 'i');
    obj();


    Function<int(char)> un = boost::bind(&quatreparams, 'a', 'b', _1, 'd');
    un('1');

    Function<int(char, char)> deux = boost::bind(&quatreparams, _1, _2, 'c', 'd');
    deux('1', '2');

    Function<int(char, char, char)> trois = boost::bind(&quatreparams, _1, _2, _3, 'd');
    trois('1', '2', '3');

    Function<int(char, char, char, char)> quatre = boost::bind(&quatreparams, _1, _2, _3, _4);
    quatre('1', '2', '3', '4');


    return 0;
}

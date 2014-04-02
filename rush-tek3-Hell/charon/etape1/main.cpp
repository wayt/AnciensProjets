#include "FunctionSignature.hpp"
#include <string>
#include <iostream>

int onefunction(std::string const& str)
{
    std::cout << str << std::endl;
    return 0;
}

void oneotherfunction(std::string const& toto, int titi)
{
    std::cout << toto << titi << std::endl;
}

int returnzero(void)
{
    return 0;
}

int main(int ac, char **av)
{
    FunctionSignature<int (const std::string& str)>::type f = &onefunction;
    f("coucou");

    FunctionSignature<void(std::string const&, int)>::type g = &oneotherfunction;
    g("Quatre: ", 4);

    FunctionSignature<int(void)>::type h = &returnzero;
    return h();
}
